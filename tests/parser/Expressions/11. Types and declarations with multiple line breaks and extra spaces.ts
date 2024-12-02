/* __________________________________________________ Варианты написания с перебросом нескольких строк и лишними пробелами __________________________________________________ */

// Объявления и выражения присваивания для типа Number
 let num_1:
        number

 ;




      let num_2: 
 number 

     = 

    5.66

 ;




    let 

  num_3 

     = 

 5.66
 
  ;




    let num_5: 
 number, 
    num_6: 
    number, 
    num_7: 
        number
        ;




    let 

            num_8 
  = 

       5.66

    , 

            num_9 

    = 

  5

     , 

 num_10 

    = 

    1000

  ;




    let num_11:
 number =  
   5.66, 
    num_12: 
    number = 
        5, 
    num_13: 
number 

 = 

1000

        ;





// Объявления и выражения присваивания для типа String
  let str_1: 
string

   ;



  let str_2: 
            string 

    = 

    "Hello, World!"

;



let 

    str_3 

= 

      "Hello, World!"

 ;




  let str_4: 
    string 
 = 

    ''

 ;




   let 

    str_5 

 = 

  ''

 ;




  let str_6: 
 string, 
        str_7: 
    string, 
 str_8: 
                string

 ;




 let 

str_9 

    = 

 "Hello, World!"

  , 

    str_10 

    = 

''

 ;




  let str_11:
    string =
    "Hello, World!", 
  str_12: 
string 

    = 

    ''

 ;





// Объявления и выражения присваивания для типа Symbol
    let sym_1: 
 symbol

        ;




 let 
    sym_2 
  = 
 Symbol

    (

            'Hello, World!'

)

        ;




    let sym_3: 
symbol, 
        sym_4: 
   symbol, 
              sym_5: 
 symbol

  ;



 let 
sym_6 

            = 

 Symbol

 (

     'Hello, World!'

        )

     ,

sym_7

   =

 Symbol

    (

     ''

)

  ;





// Объявления и выражения присваивания для типа Boolean
let bool_1:
 boolean

        ;




    let bool_2: 
  boolean 

 = 

        true

 ;




 let
     bool_3 

    = 

 false

;




    let bool_4: 
  boolean, 
          bool_5: 
    boolean, 
bool_6: 
    boolean

 ;




 let 

        bool_7 

 = 

true

    , 

 bool_8 

 = 

    false

  ;




      let bool_9: 
boolean = 
 true, 
          bool_10:
    boolean 

 = 

false

 ;





// Объявления и выражения присваивания для типа Any
 let any_1: 
  any

        ;



        let any_2: 
    any 

= 

 0.55

;




any_2 

    = 

 ''

 ;




    any_2 

 =  

true

        ;




    any_2 

 = 

"Hello, World!"

;





 any_2 

 = 

    Symbol

         (

     'Hello, World!'

    )

 ;




 let 

    any_3

 , 

      any_4

    , 

 any_5

 ;




 let any_6: 
     any = 
        0.55, 
    any_7: 
  any = 
         '', 
    any_8: 
 any = 
     true, 
 any_9: 
 any = 
         "Hello, World!", 
 any_10: 
        any 

    = 

 Symbol

  (

            'Hello, World!'

        )

    ;






// Объявления и выражения присваивания для типа Null
    let null_0: 
 null;



 let null_1: 
 null 

         = 

 null

 ;




        let null_2: 
number 
    | 

 null 

= 

    42.55

 ;



    let null_3: 
 string 
| 

null 
  = 
 "Hello, World!"
        ;



    let null_4:
 boolean 
 | 

        null 

        = 

true

    ;




 let null_5: 
    symbol 
 | 

       null 

    = 

    Symbol

 (

     'Hello, World!'

            )

 ;



 let null_6: 
     any
    |

    null

 =

''

     ;



 let null_7:
    null, 
 null_8: 
   null

    ;




let null_9: 
 number 
    | 

                null = 
 42.55, 
 null_10: 
    string 
        | 

null = 
        "Hello, World!", 
 null_11: 
        boolean 
    | 

            null = true, 
    null_12: 
symbol 
| 

    null = 
 Symbol (
          'Hello, World!'
    ), 
null_13: 
    any 
    | 

     null 

    = 

   ''

 ;





// Объявления и выражения присваивания для комбинации различных типов
 let num_01: 
    number, 
    str_01: 
string, 
  sym_01: 
symbol, 
  bool_01: 
boolean, 
 any_01: 
        any, 
null_01:
    null

    ;




let num_0001: 
  number = 42.55, 
    str_0001: 
                string = 
        "Hello, World!", 
 sym_0001: 
    symbol = 
 Symbol(
        'Hello, World!'
 ), 
    bool_0001: 
 boolean = 
 true, 
    any_0001: 
  any = 
     '', 
            null_0001: 
              null 

 = 

 null

            ;




// Объявления и выражения присваивания для типа Array
 let arr_1: 
        number

 [

]

    ;




let arr_2: 
        string

 [

]

     ;




 let arr_3: 
     symbol

 [

]

    ;




let arr_4: 
 boolean

[

    ]

 ;




    let arr_5: 
 any
  [

            ]

 ;




 let arr_6: 
 null

    [ 

]

        ;




     let 

 arr_7 

 = 

        [

                 1000

, 

      2.66

 , 

         0.55

 ]

    ;




let

    arr_8 

 = 

    [

      "Hello, World!"

     , 

     ''

]

         ;




 let 

            arr_9 

    = 

    [

        Symbol

      (

                'Hello, World!'

 )

        , 

    Symbol 

(

''

     )

 ]

        ;




 let 

    arr_10 

= 

 [

true

         ,

     false

 ]

       ;




          let 

arr_11 

  = 

[

0.55

      , 

"Hello"

    , 

        true

    , 

    null

    , 

Symbol

    (

         ''

)

        , 

    ''

 ]

            ;





let arr_12: number

 [

        ] 

 = 

 [

      1000

     , 

2.66

 , 

      0.55

    ]

  ;




 let arr_13: string

   [

            ] 

 = 

 [

      "Hello, World!"

, 

    ''

 ]

;




 let arr_14: symbol

        [
       
 ] 

= 

[

    Symbol

(

'Hello, World!'

    )

    , 

Symbol

    (

        ''

 )

    ]

 ;




 let arr_15: boolean

    [

 ] 

        = 

 [

         true

, 

     false

 ]

;




 let arr_16: any

 [

            ] 

 =

        [

0.55

    ,

    "Hello"

    ,

    true

, 

 null

    , 

    Symbol


 (
        ''

 )

    , 

        ''

    ]

 ;




 let arr_17: 
 [
    number

    , 

string

    , 

    symbol

 , 

        boolean

, 

any

        , 

    null

 ] 

    = 

 [

     0.55

, 

    "Hello"

    , 

        Symbol

(

        ''

    )

    , 

         false

    , 

''

              , 

    null

    ]

 ;




 let arr_18: 
   (

    number 

    | 

        string 

| 

    symbol 

    | 

        boolean 

| 

        any 

      | 

    null

 )

    [

            ] 

 = 

    [

     0.55

, 

    "Hello"

    , 

        Symbol

(

        ''

    )

    , 

false

 , 

    ''

    , 

 null

    ]

;
