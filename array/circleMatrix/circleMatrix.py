def main():
    size = int(input())

    maxtrix = [[0 for _ in range(size)] for _ in range(size)]

    index = 1
    loops = int (size / 2)
    length = size + 1
    count = 0

    if size % 2 != 0:
        maxtrix[loops][loops] = size ** 2
    for _ in range(loops):
        length = length - 2
        for i in range(length):
            maxtrix[count][i + count] = index
            index = index + 1
        for i in range(length):
            maxtrix[i + count][size - 1 - count] = index
            index = index + 1
        for i in range(length):
            maxtrix[size - 1 - count][size - 1 -count - i] = index
            index = index + 1
        for i in range(length):
            maxtrix[size - 1 - count - i][count] = index
            print(size-1-count-i, count, index)
            index = index + 1
        count = count + 1
    
    for i in range(size):
        print(maxtrix[i])

if __name__ == "__main__":
    main()
                
