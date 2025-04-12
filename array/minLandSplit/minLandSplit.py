import sys
input = sys.stdin.read

def main():
    #Read all input at once and split by whitespace
    data = input().split()
    index = 0

    n = int(data[0])
    m = int(data[1])
    index = 2

    array = [[0 for _ in range (m)] for _ in range (n)]
    sum_all = 0

    for i in range(n):
        for j in range(m):
            sum_all = sum_all + int(data[index])
            array[i][j] = int(data[index])
            index = index + 1
    
    horizontal = [0 for _ in range(m + 1)]
    vertical = [0 for _ in range(n + 1)]
    
    for i in range(m):
        sum_vert = 0
        for j in range(n):
            sum_vert = sum_vert + array[j][i]
        horizontal[i + 1] = horizontal[i] + sum_vert 
    
    for i in range(n):
        sum_hori = 0
        for j in range(m):
            sum_hori = sum_hori + array[i][j]
        vertical[i + 1] = vertical[i] + sum_hori 
    
    diff = float('inf')
    tem = 0

    for i in range(m):
        tem = sum_all - 2 * horizontal[i]
        diff = diff if abs(diff) < abs(tem) else tem

    for j in range(n):
        tem = sum_all - 2 * vertical[j]
        diff = diff if abs(diff) < abs(tem) else tem

    print(abs(diff))
    print(horizontal, vertical)

if __name__ == "__main__":
    main()
