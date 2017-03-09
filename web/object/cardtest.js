function Person(name,age){
	this.name=name; 
	this.age=age;
	this.Say=sayFunc;
}
function sayFunc(){
	line1="<b>Name:</b>"+this.name+"<br>\n";
	line2="<b>Age:</b>"+this.age+"<hr>\n";
	document.write(line1,line2);
}
var person1=new Person("张三",18);
var person2=new Person("李四",20);
person1.Say();
person2.Say();