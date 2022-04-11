import sys
import ctypes

# int fibFillArray(int *array, int size);
lib = ctypes.CDLL("./out/libfuncs_for_py.so")
_fibFillArray = lib.fibFillArray
_fibFillArray.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_fibFillArray.restype = ctypes.c_int

# int uniqueArray(int *array, int size, int *newArray);
_uniqueArray = lib.uniqueArray
_uniqueArray.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int), ctypes.c_int)
_uniqueArray.restype = ctypes.c_int


def uniqueArray(srcArr):
    _srcArr = (ctypes.c_int * len(srcArr))(*srcArr)
    dstSize = _uniqueArray(_srcArr, len(srcArr), None, 0)
    _dstArr = (ctypes.c_int * int(dstSize))()
    _uniqueArray(_srcArr, len(srcArr), _dstArr, dstSize)
    return list(_dstArr)

def maxSizeUniqueArray(srcArr):
    _srcArr = (ctypes.c_int * len(srcArr))(*srcArr)
    dstSize = len(srcArr)
    _dstArr = (ctypes.c_int * int(dstSize))()
    _uniqueArray(_srcArr, len(srcArr), _dstArr, dstSize)
    return list(_dstArr), _uniqueArray(_srcArr, len(_srcArr), None, 0)


def fibFillArray(size):
    if size <= 0:
        raise Exception('incorrect size')
    arr = (ctypes.c_int * size)()
    rc = _fibFillArray(arr, size)
    if rc != 0:
        raise Exception('init error');
    return list(arr)

choice = -1
while choice:
    choice = int(input("1) fib array\n2) unique array\n0) exit\n"))
    if choice == 1:
        size = int(input("input size\n"))
        print(*fibFillArray(size))
    if choice == 2:
        u_choice = -1
        while u_choice:
            u_choice = int(input("1) max_size\n2) needed size\n0) exit\n"))
            if u_choice == 1:
                arr = list(map(int, input("input array\n").split()))
                res, size = maxSizeUniqueArray(arr)
                for i in range(size):
                    print(str(res[i]) + ' ', end='')
                print('\n', end='')
            if u_choice == 2:
                arr = list(map(int, input("input array\n").split()))
                print(*uniqueArray(arr))
