def quick_sort(arr):
    """
    快速排序算法实现
    参数:
        arr: 需要排序的列表
    返回:
        排序后的列表
    """
    # 如果列表长度小于2,直接返回
    if len(arr) < 2:
        return arr
    
    # 选择基准值(这里选择第一个元素)
    pivot = arr[0]
    
    # 将列表分成三部分:小于基准值、等于基准值、大于基准值
    less = [i for i in arr[1:] if i <= pivot]
    greater = [i for i in arr[1:] if i > pivot]
    
    # 递归对子列表进行排序,并将结果合并
    return quick_sort(less) + [pivot] + quick_sort(greater)

# 测试代码
if __name__ == "__main__":
    # 测试用例
    test_arr = [3, 6, 8, 10, 1, 2, 1]
    print("排序前:", test_arr)
    sorted_arr = quick_sort(test_arr)
    print("排序后:", sorted_arr)
