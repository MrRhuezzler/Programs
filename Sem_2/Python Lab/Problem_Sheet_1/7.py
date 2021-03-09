# Write a program to compute Simple Interest (SI) and Compound
# interest (CI) for a given principal, rate of interest and duration
# in years.

si = lambda p, r, t: p * (1 + ((r / 100) * t))
ci = lambda p, r, t, n: p * ((1 + (r / 100) / n) ** (n * t))

p = float(input("Principal Amount : "))
r = float(input("Rate of Interest(%) : "))
t = float(input("Time Period : "))
n = int(input("Number of times compounded : "))

print(f"Simple Interest : {si(p,r,t) : .2f}\nCompound Interest : {ci(p, r, t, n) : .2f}")