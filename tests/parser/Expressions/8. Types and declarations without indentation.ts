/* __________________________________________________ Варианты написания без отступов __________________________________________________ */

// Объявления и выражения присваивания для типа Number
let num_1:number;
let num_2:number=5.6;
let num_3=5.66;
let num_5:number,num_6:number,num_7:number;
let num_8=5.66,num_9=5,num_10=1000;
let num_11:number=5.66,num_12:number=5,num_13:number=1000;

var num_14:number;
var num_15:number=5.6;
var num_16=5.66;
var num_17:number,num_18:number,num_19:number;
var num_20=5.66,num_21=5,num_21=1000;
var num_22:number=5.66,num_23:number=5,num_24:number=1000;

const num_25:number=5.6;
const num_26=5.66;
const num_27=5.6,num_28=5,num_29=1000;
const num_30:number=5.66,num_31:number=5,num_32:number=1000;


// Объявления и выражения присваивания для типа String
let str_1:string;
let str_2:string="Hello, World!";
let str_3="Hello, World!";
let str_4:string='';
let str_5='';
let str_6:string,str_7:string,str_8:string;
let str_9="Hello, World!",str_10='';
let str_11:string="Hello, World!",str_12:string='';

var str_13:string;
var str_14:string="Hello, World!";
var str_15="Hello, World!";
var str_16:string='';
var str_17='';
var str_18:string,str_19:string,str_20:string;
var str_21="Hello, World!",str_22='';
var str_23:string="Hello, World!",str_24:string='';

const str_25:string="Hello, World!";
const str_26="Hello, World!";
const str_27:string='';
const str_28='';
const str_29="Hello, World!",str_30='';
const str_31:string="Hello, World!",str_32:string='';


// Объявления и выражения присваивания для типа Symbol
let sym_1:symbol;
let sym_2=Symbol('Hello, World!');
let sym_3:symbol,sym_4:symbol,sym_5:symbol;
let sym_6=Symbol('Hello, World!'),sym_7=Symbol('');

var sym_8:symbol;
var sym_9=Symbol('Hello, World!');
var sym_10:symbol,sym_11:symbol,sym_12:symbol;
var sym_13=Symbol('Hello, World!'),sym_14=Symbol('');

const sym_15=Symbol('Hello, World!');
const sym_16=Symbol('Hello, World!'),sym_17=Symbol('');


// Объявления и выражения присваивания для типа Boolean
let bool_1:boolean;
let bool_2:boolean=true;
let bool_3=false;
let bool_4:boolean,bool_5:boolean,bool_6:boolean;
let bool_7=true,bool_8=false;
let bool_9:boolean=true,bool_10:boolean=false;

var bool_11:boolean;
var bool_12:boolean=true;
var bool_13=false;
var bool_14:boolean,bool_15:boolean,bool_16:boolean;
var bool_17=true,bool_18=false;
var bool_19:boolean=true,bool_20:boolean=false;

const bool_21:boolean=true;
const bool_22=false;
const bool_23=true,bool_24=false;
const bool_25:boolean=true,bool_26:boolean=false;


// Объявления и выражения присваивания для типа Any
let any_1:any;
let any_2:any=0.55;
any_2='';
any_2=true;
any_2="Hello, World!";
any_2=Symbol('Hello, World!');
let any_3,any_4,any_5;
let any_6:any=0.55,any_7:any='',any_8:any=true,any_9:any="Hello, World!",any_10:any=Symbol('Hello, World!');

var any_11:any;
var any_12:any=0.55;
any_12='';
any_12=true;
any_12="Hello, World!";
any_12=Symbol('Hello, World!');
var any_13,any_14,any_15;
var any_16:any=0.55,any_17:any='',any_18:any=true,any_19:any="Hello, World!",any_20:any=Symbol('Hello, World!');

const any_21:any=0.55;
const any_22:any='';
const any_23:any=true;
const any_24:any="Hello, World!";
const any_25:any=Symbol('Hello, World!');
const any_26:any=0.55,any_27:any='',any_28:any=true,any_29:any="Hello, World!",any_30:any=Symbol('Hello, World!');


// Объявления и выражения присваивания для типа Null
let null_0:null;
let null_1:null=null;
let null_2:number|null=42.55;
let null_3:string|null="Hello, World!";
let null_4:boolean|null=true;
let null_5:symbol|null=Symbol('Hello, World!');
let null_6:any|null='';
let null_7:null,null_8:null;
let null_9:number|null=42.55,null_10:string|null="Hello, World!",null_11:boolean|null=true,null_12:symbol|null=Symbol('Hello, World!'),null_13:any|null='';

var null_14:null;
var null_15:null=null;
var null_16:number|null=42.55;
var null_17:string|null="Hello, World!";
var null_18:boolean|null=true;
var null_19:symbol|null=Symbol('Hello, World!');
var null_20:any|null='';
var null_21:null,null_22:null;
var null_23:number|null=42.55,null_24:string|null="Hello, World!",null_25:boolean|null=true,null_26:symbol|null=Symbol('Hello, World!'),null_27:any|null='';

const null_28:null=null;
const null_29:number|null=42.55;
const null_30:string|null="Hello, World!";
const null_31:boolean|null=true;
const null_32:symbol|null=Symbol('Hello, World!');
const null_33:any|null='';
const null_34:number|null=42.55,null_35:string|null="Hello, World!",null_36:boolean|null=true,null_37:symbol|null=Symbol('Hello, World!'),null_38:any|null='';


// Объявления и выражения присваивания для комбинации различных типов
let num_01:number,str_01:string,sym_01:symbol,bool_01:boolean,any_01:any,null_01:null;
var num_001:number,str_001:string,sym_001:symbol,bool_001:boolean,any_001:any,null_001:null;

let num_0001:number=42.55,str_0001:string="Hello, World!",sym_0001:symbol=Symbol('Hello, World!'),bool_0001:boolean=true,any_0001:any='',null_0001:null=null;
var num_00001:number=42.55,str_00001:string="Hello, World!",sym_00001:symbol=Symbol('Hello, World!'),bool_00001:boolean=true,any_00001:any='',null_00001:null=null;
const num_000001:number=42.55,str_000001:string="Hello, World!",sym_000001:symbol=Symbol('Hello, World!'),bool_000001:boolean=true,any_000001:any='',null_000001:null=null;


// Объявления и выражения присваивания для типа Array
let arr_1:number[];
let arr_2:string[];
let arr_3:symbol[];
let arr_4:boolean[];
let arr_5:any[];
let arr_6:null[];
let arr_7=[1000,2.66,0.55];
let arr_8=["Hello, World!",''];
let arr_9=[Symbol('Hello, World!'),Symbol('')];
let arr_10=[true,false];
let arr_11=[0.55,"Hello",true,null,Symbol(''),''];
let arr_12:number[]=[1000,2.66,0.55];
let arr_13:string[]=["Hello, World!",''];
let arr_14:symbol[]=[Symbol('Hello, World!'),Symbol('')];
let arr_15:boolean[]=[true,false];
let arr_16:any[]=[0.55,"Hello",true,null,Symbol(''),''];
let arr_17:[number,string,symbol,boolean,any,null]=[0.55,"Hello",Symbol(''),false,'',null];// кортеж (tuple)
let arr_18:(number|string|symbol|boolean|any|null)[]=[0.55,"Hello",Symbol(''),false,'',null];

var arr_19:number[];
var arr_20:string[];
var arr_21:symbol[];
var arr_22:boolean[];
var arr_23:any[];
var arr_24:null[];
var arr_25=[1000,2.66,0.55];
var arr_26=["Hello, World!",''];
var arr_27=[Symbol('Hello, World!'),Symbol('')];
var arr_28=[true,false];
var arr_29=[0.55,"Hello",true,null,Symbol(''),''];
var arr_30:number[]=[1000,2.66,0.55];
var arr_31:string[]=["Hello, World!",''];
var arr_32:symbol[]=[Symbol('Hello, World!'),Symbol('')];
var arr_33:boolean[]=[true,false];
var arr_34:any[]=[0.55,"Hello",true,null,Symbol(''),''];
var arr_35:[number,string,symbol,boolean,any,null]=[0.55,"Hello",Symbol(''),false,'',null];// кортеж (tuple)
var arr_36:(number|string|symbol|boolean|any|null)[]=[0.55,"Hello",Symbol(''),false,'',null];

const arr_37=[1000,2.66,0.55];
const arr_38=["Hello, World!",''];
const arr_39=[Symbol('Hello, World!'),Symbol('')];
const arr_40=[true,false];
const arr_41=[0.55,"Hello",true,null,Symbol(''),''];
const arr_42:number[]=[1000,2.66,0.55];
const arr_43:string[]=["Hello, World!",''];
const arr_44:symbol[]=[Symbol('Hello, World!'),Symbol('')];
const arr_45:boolean[]=[true,false];
const arr_46:any[]=[0.55,"Hello",true,null,Symbol(''),''];
const arr_47:[number,string,symbol,boolean,any,null]=[0.55,"Hello",Symbol(''),false,'',null];// кортеж (tuple)
const arr_48:(number|string|symbol|boolean|any|null)[]=[0.55,"Hello",Symbol(''),false,'',null];
