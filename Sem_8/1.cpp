// The first thread becomes the leader of the group
// The leader thread waits for a "Fixed time" for others to arrive
// Those who arrived start running
// Barrier to wait for all the threads to finish
// Thread that misses 5 running sessions leave the running group
// Thread that runs 10 times alone leaves the running group

#include <iostream>
#include <random>
#include <omp.h>
#include <thread>
#include <chrono>

#define NUM_THREADS 10
#define EXHAUSTED_RUNS 20
#define MAX_SOLO_RUNS 10
#define MAX_MISSED_RUNS 5

class Runner
{
public:
	static const int runningSessionWaitTime;
	static bool sessionStart;
	static int currentRunners;
	static bool waitingForLeader;

	int id, studyTime, runningTime;
	int runs_completed = 0, missed_sessions = 0, solo_runs = 0;

public:
	Runner() {}
	Runner(int id, int studyTime, int runningTime)
	{
		this->id = id;
		this->studyTime = studyTime;
		this->runningTime = runningTime;
	}

	void run()
	{
		bool isRunnable = true;
		bool isLeader;
		bool missedRun = false;

		while (true)
		{
			isLeader = false;

			// Study Time
			if (isRunnable && !missedRun)
			{
				std::this_thread::sleep_for(std::chrono::seconds(this->studyTime));
			}

			if (isRunnable)
			{
#pragma omp single nowait
				{
					isLeader = true;
					missedRun = false;
					Runner::currentRunners++;
					std::this_thread::sleep_for(std::chrono::seconds(Runner::runningSessionWaitTime));
					Runner::sessionStart = true;
				}
			}

			if (isRunnable)
			{
#pragma omp critical
				{
					if (!isLeader)
					{
						if (!Runner::sessionStart)
						{
							missedRun = false;
							Runner::currentRunners++;
						}
						else
						{
							this->missed_sessions++;
							if (this->missed_sessions > MAX_MISSED_RUNS)
							{
								std::cout << "r" << id << " stopped after " << runs_completed << " run(s)."
										  << " He missed " << missed_sessions << " run(s) and did run " << solo_runs << " times alone." << std::endl;
								isRunnable = false;
							}
							missedRun = true;
						}
					}
				}
			}
#pragma omp barrier

			if (!isRunnable)
			{
#pragma omp critical
				{
					if (isLeader)
					{
						if (Runner::currentRunners == 1)
							this->solo_runs++;
					}
				}
			}

			if (isRunnable && !missedRun)
			{

				// Run Time
				std::this_thread::sleep_for(std::chrono::seconds(this->runningTime));
				this->runs_completed++;

				if (this->runs_completed >= EXHAUSTED_RUNS || this->solo_runs >= MAX_SOLO_RUNS)
				{
					std::cout << "r" << id << " stopped after " << runs_completed << " run(s)."
							  << " He missed " << missed_sessions << " run(s) and did run " << solo_runs << " times alone." << std::endl;
					isRunnable = false;
				}
			}

			if (!isRunnable)
			{
#pragma omp single
				{
					Runner::currentRunners = 0;
					Runner::sessionStart = false;
				}
			}
#pragma omp barrier
		}
	}
};

bool Runner::sessionStart = false;
bool Runner::waitingForLeader = false;
int Runner::currentRunners = 0;
const int Runner::runningSessionWaitTime = 2;

int main()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> rdist(1, 5);
	std::uniform_int_distribution<std::mt19937::result_type> sdist(1, 5);

	int runningTimes[NUM_THREADS] = {0};
	int studyTimes[NUM_THREADS] = {0};
	for (int i = 0; i < NUM_THREADS; i++)
	{
		runningTimes[i] = rdist(rng);
		studyTimes[i] = sdist(rng);
		// std::cout << "Wait Times (" << i << ") : " << runningTimes[i] << "\t"
		//           << "Study Times (" << i << ") : " << studyTimes[i] << std::endl;
	}

	Runner runners[NUM_THREADS];

	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
	{
		int id = omp_get_thread_num();
		runners[id].id = id;
		runners[id].studyTime = studyTimes[id];
		runners[id].runningTime = runningTimes[id];
		runners[id].run();
	}

	// for (int i = 0; i < NUM_THREADS; i++)
	// {
	// 	Runner r = runners[i];
	// 	std::cout << "r" << id << " stopped after " << runs_completed << " run(s)."
	// 		<< " He missed " << missed_sessions << " run(s) and did run " << solo_runs << " times alone." << std::endl;
	// }

	return 0;
}
