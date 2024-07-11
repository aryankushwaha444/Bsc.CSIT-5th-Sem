const a = 34;
const b =34;
const c =34;

if(a>b){
    console.log("a is greatest than b")
}
else{
    console.log("a is smallest than b")
}



// WAP to find the given number is positive or negative

if(a>=0)
    {
        console.log("a is positive number")
    }
else{
    console.log("a is negative number")
}    


// WAP to find lowest and heighest number between three numbers
if(a == b && b==c)
    {
        console.log("All are same",a)
    }
else if(a>b && a>c){
    console.log("a is highest number = ",a)
}
else if(b>a && b>c){
    console.log("b is highest number = ",b)
}
else{
    console.log("c is highest number = ",c)
}

if(a == b && b==c)
    {
        console.log("All are same",a)
    }

else if(a<b && a<c){
    console.log("b is lowest number = ",b)

}

else if(b<a && b<c){
    console.log("b is lowest number = ",b)

}
else{
    console.log("c is lowest number = ",c)

}