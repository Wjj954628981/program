function cleardesc(){
	d=document.getElementById("description");
	d.innerHTML="";
}
function hover(e){
	if(!e) var e=window.event;
	//which link was the mouse over?
	whichlink=(e.target)?e.target.id:e.srcElement.id;
	//choose the approriate description
	if(whichlink=="order") desc="Order a product";
	else if(whichlink=="email") desc="Send us a message";
	else if(whichlink=="complain") desc="Insult us, our products, or our families";
	//display the description in the H2
	d=document.getElementById("description");
	d.innerHTML=desc;
}
//Set up the event handlers
orderlink=document.getElementById("order");
orderlink.onmouseover=hover;
orderlink.onmouseout=cleardesc;
emaillink=document.getElementById("email");
emaillink.onmouseover=hover;
emaillink.onmouseout=cleardesc;
complainlink=document.getElementById("complain");
complainlink.onmouseover=hover;
complainlink.onmouseout=cleardesc;