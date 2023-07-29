Notes on pointers :\

* is dereference operator and & is reference operator\
dereference means "go to the value of the address"\

dot vs arrow operator:\
To access members of a structure, use the dot operator. To access members of a\ structure through a pointer, use the arrow operator.\

A note on arrays:\
    <!-- 
    int a[2] = {2,3}; same address
    int * aPtr = a;   same address
    cout<<a<<endl;    same address
    cout<<aPtr<<endl;
    cout<<*(&aPtr)<<endl;
    cout<<*aPtr<<endl;
    cout<<*(++aPtr)<<endl; 
    -->