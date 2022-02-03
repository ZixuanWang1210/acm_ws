

def number_of_1_in_binary_fast(num):
    count = 0
    while num:
        if num < - MAX_INT - 1 or num > MAX_INT:
            break
        print("iter %d: %d" % (count, num))
        count += 1
        num = num & (num-1)
        
    return count

n=input()
m=input()

cnt=int_Conter(m)
t=n**cnt%1000000007
print(t)
