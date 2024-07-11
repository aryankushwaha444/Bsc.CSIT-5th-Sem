/* 1. WAP to check whether a number is divided by 5
2. WAP to check whether a number is divisible by 5 and 11 or not
3. WAP to check whether a number is even or odd
4. WAP to input marks of five subjects physics , chemistry , biology , Mathematics and computer , calculate percentage and grade according to given conditions:

*/

// Q.No. 1
/*
function DivBy5() {
    let num  = parseFloat(prompt("Enter any number : "))

    if (num % 5 === 0) {
        alert(`${num} is divisible by 5.`);
    } else {
        alert(`${num} is not divisible by 5.`);
    }
}

DivBy5(); */


// Q.No. 2
/*
function DivBy5And11() {
    let num  = parseFloat(prompt("Enter any number : "))
    if (num % 5 === 0 && num % 11 === 0) {
        alert(`${num} is divisible by both 5 and 11.`);
    } else {
        alert(`${num} is not divisible by both 5 and 11.`);
    }
}
DivBy5And11();  */


// Q. No. 3
/*
function EvenOrOdd() {
    let num  = parseFloat(prompt("Enter any number : "))
    if (num % 2 === 0) {
        alert(`${num} is even.`);
    } else {
        alert(`${num} is odd.`);
    }
}

EvenOrOdd();  */



// Q.No. 4
/*
function result() {
    let physics = parseFloat(prompt("Enter marks for Physics:"));
    let chemistry = parseFloat(prompt("Enter marks for Chemistry:"));
    let biology = parseFloat(prompt("Enter marks for Biology:"));
    let mathematics = parseFloat(prompt("Enter marks for Mathematics:"));
    let computer = parseFloat(prompt("Enter marks for Computer:"));

    let totalMarks = physics + chemistry + biology + mathematics + computer;
    let percentage = (totalMarks / 500) * 100;
    let grade;

    if (percentage >= 90) {
        grade = 'A';
    } else if (percentage >= 80) {
        grade = 'B';
    } else if (percentage >= 70) {
        grade = 'C';
    } else if (percentage >= 60) {
        grade = 'D';
    } else if (percentage >= 40) {
        grade = 'E';
    } else {
        grade = 'F';
    }

    alert(`Percentage: ${percentage}%`);
    alert(`Grade: ${grade}`);
}

result(); */
