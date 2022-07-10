from dataclasses import dataclass
from email import charset
from cyaron import *  # 引入CYaRon的库

test_data = IO(file_prefix="heat", disable_output=True)
test_data.input_writeln(100)
for i in range(0,100):
    str=String.random(100,charset='henuxabc')
    test_data.input_writeln(str)

# _n = ati([10, 100, 1000, 10000, 100000, 1000, 10000, 1000000])
# _q = ati([1, 10, 100, 1000, 100000, 1000, 10000, 100000])
# for i in range(0, 8):

#     n = _n[i]
#     q = _q[i]
#     # length=randint(1,n)
#     length = n

#     test_data.input_writeln(length)

#     test_data.input_writeln(String.random(length))

#     # q=randint(1,q)
#     test_data.input_writeln(q)
#     for j in range(1, q+1):
#         l = randint(1, 1000)
#         r = randint(100000, 1000000)
#         test_data.input_writeln(l, r)
