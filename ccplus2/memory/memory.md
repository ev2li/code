# __<center><font color="#006666">内存</font></center>__
## __<font color="#006666">内存大小</font>__
- 内存对齐
- 空类的大小
- 包含1到N个虚函数的类内存大小
- 有继承的虚函数类的大小

## __<font color="#006666">内存分配</font>__
- new/delete, new[] / delete[]
- placement new
- malloc/free
- ::operator new ::operator delete
- 重载operator new operator delete

## __<font color="#006666">实际分配内存和返回给用户的内存</font>__
![图片](../pics/malloc内存分配.png)
- cookie记录分配的内存大小 4byte 2个cookie 8byte 值为0x00000041 = 64 + 1(这个1是表示内存被分配出去了，不是内存大小) 4* 16 = 64
- Debug header：32byte
- Debug tail:固定4byte
- 内存最终是16的倍数(根据平台的不同)
  
![图片](../pics/%E5%86%85%E5%AD%98%E5%88%86%E9%85%8D%E8%AE%A1%E7%AE%97.png)

![图片](../pics/内存图.jpg)

  


