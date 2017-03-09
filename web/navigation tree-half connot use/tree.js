function Toggle(e){
	//Don't try this in old browsers
	if(!document.getElementById) return;
	//Get the event object
	if(!e) var e =window.event;
	//which link was clicked?
	whichlink=(e.target)?e.target.id:e.srcElement.id;
	//get the menu object
	obj=document.getElementById(whichlink+"menu");
	//Is the menu visible?
	visible=(obj.style.display=="block");
	//Get the key object(the link itself)
	//This line is wrong
	//key=document.getElementById(whicklink);
	//Get the name(Products,Contact,etc.)
	//keyname=key.firstChild.nodeValue.substring(3);
	if(visible){
		//hide the menu
		obj.style.display="none";
		//key.firstChild.nodeValue="[+]"+whichlink;
	}else{
		//show the menu
		obj.style.display="block";
		//key.firstChild.nodeValue="[-]"+whichlink;
	}
}
document.getElementById("products").onclick=Toggle;
document.getElementById("support").onclick=Toggle;
document.getElementById("contact").onclick=Toggle;