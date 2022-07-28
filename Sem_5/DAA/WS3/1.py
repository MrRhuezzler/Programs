def possibleLogsAtHeight(heights, height):
    total = 0
    for tree in heights:
        if tree > height:
            total += (tree - height)
    return total

if __name__ == "__main__":

    #heights = [20, 15, 10, 17]
    heights = [4, 26, 40, 42, 46]
    #K = 7
    K = 35

    # O(n)
    maximumHeight = max(heights)

    # O(nlogn)
    low = 0
    high = maximumHeight
    mid = mid = (high + low) / 2

    while(high > low):
        if K > possibleLogsAtHeight(heights, mid):
            high = mid - 1
        elif K == possibleLogsAtHeight(heights, mid):
            break
        else:
            low = mid + 1
        mid = (high + low) / 2

    print("Desired Height: ", mid)
    print("Wood Collected: ", possibleLogsAtHeight(heights, mid))
    print([x if x <= mid else x - (x - mid) for x in heights])
