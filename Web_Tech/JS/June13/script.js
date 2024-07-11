const players = ['messi' , 'ronaldo' , 'neymar' , 'aguera'];
// console.log(players); 
// Array = players.join(" and ");
// console.log(Array);
// console.log(players.toString());


/* research 
foreach()
filter()
map()
reduce()
find()
findindex()
every()
some()
*/



players.forEach((val)=>{
    console.log(val);
});

let num = [5,2,3,4,5,5,6,7,7]
  let n = num.reduce((n1,n2)=>{
    return n1 +n2;
})
console.log(n)

let num2 = num.every((ev) =>{
    return ev>1;

})
console.log(num2);

let car = [{price:354} , {price:345}

]

let num3 = car.find((ev) =>{
    return ev.price > 345;

})
console.log(num3);

let num4  = num.some((v)=>{
    return v > 6;
})
console.log(num4);
