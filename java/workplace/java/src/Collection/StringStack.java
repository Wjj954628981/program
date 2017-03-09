package Collection;

import java.util.*;

public class StringStack {
    private LinkedList<String> linkedList;
    public StringStack() {
        linkedList = new LinkedList<String>();
    }
    public void push(String name) {
        //将元素加入串行前端
        linkedList.addFirst(name);
    }
    public String top() {
        //取得串行第一个元素
        return linkedList.getFirst();
    }
    public String pop() {
        //移出第一个元素
        return linkedList.removeFirst();
    }
    public boolean isEmpty() {
        //串行是否为空
        return linkedList.isEmpty();
    }
    public static void main(String[] args) {
    	StringStack sstack=new StringStack();
    	sstack.push("first");
    	sstack.push("second");
    	sstack.push("third");
    	
    	while(!sstack.isEmpty()){
    		System.out.println(sstack.pop());
    	}    	
    }
}
