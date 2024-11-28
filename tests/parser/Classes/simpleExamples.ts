// 1
class A {}
// 2
class B extends A {}
// 3
class C {
    constructor() {}
}
// 4
class C1 {
    constructor(a, b:number, c?, d = 2,) {}
}

// 5
class C2 {
    constructor(a: [null, number], ...b) {}
}
// 6
class C3 {
    c3_a;
    c3_b: number;
    c3_c = 2;

    f() {}
    f1(a, b: number, c?: [], ...d): void {}
}

// 7
class
    C4
        
    {
constructor
(
    a
    ,
     
    b
    :
    number
    ,
     
    c
    ?
    ,
     
    d
     
    =
     
    2
    ,
)
 
{

}

        c3_a
    
            c3_b
            :
 number
;

    c3_c
         =  
        
         2

f1
(
    a
    ,
     
b
:
 number
 , 
 c
 
 ?
 :
 
 [

 ]
 ,
  
 ...
 
 d
)

:
 
void
 
{


}

}

// 8
class C5 {
    "str_lit" = 1
    123 = 2
    555.999 = 3;
    [`asd`]: number = 2;
    [321] = 2;
}