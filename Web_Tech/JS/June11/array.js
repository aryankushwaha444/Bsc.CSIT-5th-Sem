//  Array

// Definig an array
/*
const arry = [1,2,4,5,5];
console.log("Array")
console.log(arry)


const newArry = new Array(1,2,3,4,5,6);
console.log("New Array")
console.log(newArry)


// Accessing array using index
console.log(arry[2])
console.log(arry[4])

arry[2] = 9
console.log(arry[2])

arry[5] = 234
arry[6] = 4
arry[7] = 21
arry[8] = 24
arry[9] = 34
console.log(arry)

arry[14] = 234
console.log(arry)

// Push and pop

arry.push("Aryal")
arry.push("Madhu")
console.log(arry)
arry.pop()
console.log(arry)
*/


// Loops with array accesing with index No.
/*
const students = [
    "Kushwaha" , "Aryal", "Gautam " , "Raymaghi" , "Shrestha"
];

console.log(students)

//  for loop
for(let i = 0; i<students.length;i++)
    {
        console.log(`Hi , ${students[i]}`)
    }


    // for of loop
    for(let student of students)
        {
            console.log(`${student}`)
        }
*/

// June 12
// Array Method
/*
const asia = ['Nepal', 'India' , 'China']
console.log(asia)
const europ = ['France' , 'Germany' , 'Spain']
console.log(europ)

const  allCountries = asia.concat(europ)
console.log(allCountries)


const provinces = ['Koshi' , 'Madhesh' ,' Bagmati' , 'Lumbini' , 'Gandaki' , 'Karnali' , 'Sudhur Paschim']
console.log(provinces)
provinces.splice(1,0,'New Province') //Insert "Madhesh" next at 1 index
console.log(provinces)

provinces.splice(1,3,'Lumbini2')  // index no. , delete index , add at index
console.log(provinces)


*/

// Slice()
const animals = ['Dog' , 'cat' , 'Elephent' , 'Cow']
console.log(animals)
const newAnimals = animals.slice(1,3)
console.log(newAnimals)
const newAnimalss = animals.slice(-2)
console.log(newAnimalss)


const faculty = 'BBM'
const faculties = ['BCA' , 'CSIT','BBM' ,'BIM','BBA']
console.log(faculties)

// faculties.pop(faculties[index])
// console.log(faculties)

const index = faculties.indexOf(faculty)
console.log(index)
faculties.splice(index+1,1)
console.log(faculties)

