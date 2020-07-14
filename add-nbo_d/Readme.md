syntax : add-nbo \<file1\> \<file2\><br>
sample : add-nbo a.bin c.bin<br>
<br>
# Usage<br>
<br>
$ echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin<br>
$ echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin<br>
$ ./add-nbo thousand.bin five-hundred.bin<br>
1000(0x3e8) + 500(0x1f4) = 1500(0x5dc)<br>

