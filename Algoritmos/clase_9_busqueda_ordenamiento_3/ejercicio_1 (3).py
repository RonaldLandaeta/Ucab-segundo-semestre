"""
Dada una lista de cadenas, implementa MergeSort para ordenarlas en 
orden ascendente según la longitud de las cadenas.
"""

def merge_sort_by_length(array):
    if len(array) > 1:
        mid = len(array) // 2
        left_half = array[:mid]
        right_half = array[mid:]

        merge_sort_by_length(left_half)
        merge_sort_by_length(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if len(left_half[i]) < len(right_half[j]):
                array[k] = left_half[i]
                i += 1
            else:
                array[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            array[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            array[k] = right_half[j]
            j += 1
            k += 1

if __name__ == "__main__":
    strings = ["manzana", "cambur", "kiwi", "cereza", "mango", "melocotón"]
    merge_sort_by_length(strings)
    print("String ordenados por longitud:", strings)
