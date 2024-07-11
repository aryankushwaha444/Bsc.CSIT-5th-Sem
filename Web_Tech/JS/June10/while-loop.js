// Syntax

/*
1. while loop

*/

/*
let i =1;
while (i != 11) {
    console.log(i)
    i++
    
}

let j =1

do {
    console.log(j)
    j++
    
} while (j !=11);

*/




do {
    let num
  num = parseInt(prompt("Enter any number : "))
    if(num > 100)
        {
            console.log("Enter your number is greater = ",num)

        }
    else if(num == 10)
        {
            console.log("Enter your number is equal ", num)
        }

    else
    {
                console.log("Enter your number is less ",num)
            }
        
    
} while (num <=100);
 

// Multiplicatin
/*
let num;
let i=1;
num = prompt("Enter any number : ");

do {
    console.log(`${num} x ${i} =  ${num * i}`);
    i++

} while (i<= 10);
*/

// WAP that calculate the sum of numbers from 1 to n using a while loop
/*
let num;
let sum = 0;
let i = 1;
num = prompt("Enter a sum number ");
while (i <= num) {
  sum += i;
  i++;
}
console.log(sum);
*/
