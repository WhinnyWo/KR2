def binary_search(arr, target):
    """
    Бинарный поиск в отсортированном массиве
    """
    left, right = 0, len(arr) - 1
    step = 1
    
    print(f"Ищем {target} в массиве: {arr}")
    
    while left <= right:
        mid = (left + right) // 2
        print(f"Шаг {step}: left={left}, right={right}, mid={mid} (элемент {arr[mid]})")
        
        if arr[mid] == target:
            print(f"✓ Нашли на позиции {mid}!")
            return mid
        elif arr[mid] < target:
            print(f"  {arr[mid]} < {target} - ищем в правой половине")
            left = mid + 1
        else:
            print(f"  {arr[mid]} > {target} - ищем в левой половине")
            right = mid - 1
        
        step += 1
    
    print("✗ Элемент не найден")
    return -1

# Пример использования
sorted_numbers = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
target = 13

print("БИНАРНЫЙ ПОИСК")
print("=" * 30)
result = binary_search(sorted_numbers, target)
