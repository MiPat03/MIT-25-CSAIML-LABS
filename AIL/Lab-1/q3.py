def euclidean_distance(x,y):
    sq = 0
    for px,py in zip(x,y):
        sq += (py-px)**2
        return sq**0.5

x = [(0,0),(0,0),(0,0)]
y = [(3,4),(7,24),(5,12)]

def bubble_sort(arr):
    for i in range(1,len(arr)):
        for j in range(len(arr)-1):
            if(arr[j] > arr[j+1]):
                if(arr[j] > arr[j+1]):
                    arr[j],arr[j+1] = arr[j+1],arr[j]
                    return arr

dists = [euclidean_distance(x,y) for x,y in zip(x,y)]
print(dists)
print(bubble_sort(dists))