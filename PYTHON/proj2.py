def bubble_sort(array):
    for i in range(len(array) - 1):
        for j in range(len(array) - i - 1):
            if array[j] > array[j + 1]:
                temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp


def insertion_sort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key


def quick_sort(array, low, high):
    if low < high:
        pivot = partition(array, low, high)
        quick_sort(array, low, pivot - 1)
        quick_sort(array, pivot + 1, high)


def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] <= pivot:
            i += 1
            temp = array[i]
            array[i] = array[j]
            array[j] = temp
    temp = array[i + 1]
    array[i + 1] = array[high]
    array[high] = temp
    return i + 1


def selection_sort(array):
    for i in range(len(array) - 1):
        min_index = i
        for j in range(i + 1, len(array)):
            if array[j] < array[min_index]:
                min_index = j

        if min_index != i:
            temp = array[i]
            array[i] = array[min_index]
            array[min_index] = temp


def print_array(array):
    for element in array:
        print(element, end=" ")
    print()


def merge_sort(array):
    if len(array) <= 1:
        return

    mid = len(array) // 2
    left = array[:mid]
    right = array[mid:]

    merge_sort(left)
    merge_sort(right)

    merge(array, left, right)


def merge(array, left, right):
    i = 0
    j = 0
    k = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            array[k] = left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1
        k += 1

    while i < len(left):
        array[k] = left[i]
        i += 1
        k += 1

    while j < len(right):
        array[k] = right[j]
        j += 1
        k += 1

def print_array(array):
    for element in array:
        print(element, end=" ")
    print()

    
def main():
    n = int(input("Enter the number of elements of the array:"))
    array = []
    for i in range(n):
        array.append(int(input(f"Enter element {i+1}: ")))

    print("Menu:")
    print("1. Bubble sort")
    print("2. Insertion sort")
    print("3. Quick sort")
    print("4. Selection sort")
    print("5. Merge sort")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        bubble_sort(array)
    elif choice == 2:
        insertion_sort(array)
    elif choice == 3:
        quick_sort(array, 0, len(array) - 1)
    elif choice == 4:
        selection_sort(array)
    elif choice == 5:
        merge_sort(array)
    else:
        print("Invalid choice.")
        return

    print("Sorted array:")
    print_array(array)


if __name__ == "__main__":
    main()
