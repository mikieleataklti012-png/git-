let john = { name: "John", age: 25 };
let pete = { name: "Pete", age: 30 };
let mary = { name: "Mary", age: 28 };

let arr = [ pete, john, mary ];

sortByAge(arr);
 
function sortByAge(arr){
    let sorted={name:"n", age:"a"}
    for(let i=0;i<arr.length;i++){
        sorted=arr.sort((a,b)=>a.age-b.age);
    }
        console.log(sorted);
}