from cyaron import *  # 引入CYaRon的库

_n = ati([10, 100, 1000, 10000, 100000, 1000, 10000, 1000000])
_q = ati([1, 10, 100, 1000, 100000, 1000, 10000, 100000])
for i in range(0, 8):
    test_data = IO(file_prefix="heat", data_id=i, disable_output=True)

    n = _n[i]
    q = _q[i]
    # length=randint(1,n)
    length = n

    test_data.input_writeln(length)

    test_data.input_writeln(String.random(length))

    # q=randint(1,q)
    test_data.input_writeln(q)
    for j in range(1, q+1):
        l = randint(1, 1000)
        r = randint(100000, 1000000)
        test_data.input_writeln(l, r)
