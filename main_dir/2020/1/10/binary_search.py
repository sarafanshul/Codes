# ------------------for BINARY SEARCH ,DATA must be SORTED--------------
# data.sort()
# data = list(range(0, 100, 2))+[10]
data = [0 , 1 , 1 , 10]
target = 10

# # iterative binary search algorithm
def binary_search_iter( data , target):
    low = 0

# How the fuck it checks for the data at last index
# because 'indexing starts from 0 and length starts form 1'
    high = len(data) - 1

    while low <= high:
        mid = (low + high) // 2
        if target == data[mid]:
            return f'Index of {target} = {mid}'
        elif target < data[mid]:
            high = mid - 1
        else:
            low = mid + 1
    return f'{target} not present in data'



#RECURSIVE Binary search
def bin_search_rec( data , target , high , low ):
    
    if low > high:
        return f'Negative'
    else:
        mid = (low + high)// 2
        if target == data[mid]:
            return f'{target} at {mid}'
        elif target < data[mid]:
            return bin_search_rec(data , target , mid-1 , low )
        else:
            return bin_search_rec(data, target, high , mid+1 )


# if __name__ == '__main__':
#     print(binary_search_iter(data , target))
#     print(bin_search_rec(data , target , len(data)-1 , 0))
    