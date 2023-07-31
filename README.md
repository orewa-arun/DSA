Notes on pointers :\

* is dereference operator and & is reference operator\
dereference means "go to the value of the address"\

dot vs arrow operator:\
To access members of a structure, use the dot operator. To access members of a\ structure through a pointer, use the arrow operator.\

A note on arrays:\
    <!-- 
    int a[2] = {2,3}; 
    int * aPtr = a;   
    cout<<a<<endl;           same address
    cout<<aPtr<<endl;        same address
    cout<<*(&aPtr)<<endl;    same address
    cout<<*aPtr<<endl;       first element 2
    cout<<*(++aPtr)<<endl;   second element 3
    -->