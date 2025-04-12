import sys
input = sys.stdin.read

def main():
    # Read all input at once and split by whitespace
    data = input().split()
    index = 0

    # First value is the length of the array
    n = int(data[index])
    index += 1

    # Read n integers into the array 'vec'
    vec = []
    for i in range(n):
        vec.append(int(data[index + i]))
    index += n

    # Build prefix sum array 'p'
    p = [0] * n
    presum = 0
    for i in range(n):
        presum += vec[i]
        p[i] = presum

    results = []

    # Process multiple queries (pairs of a and b)
    while index < len(data):
        a = int(data[index])
        b = int(data[index + 1])
        index += 2

        # If a is 0, the sum is simply p[b]
        if a == 0:
            sum_value = p[b]
        else:
            # Otherwise, subtract the prefix sum up to a-1
            sum_value = p[b] - p[a - 1]

        results.append(sum_value)

    # Print results of all queries
    for result in results:
        print(result)

if __name__ == "__main__":
    main()

