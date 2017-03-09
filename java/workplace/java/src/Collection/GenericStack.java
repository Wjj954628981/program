package Collection;

import java.util.*;

public class GenericStack<T>{
    private LinkedList<T> linkedList;
    public GenericStack() {
        linkedList = new LinkedList<T>();
    }
    public void push(T name) {
        //将元素加入串行前端
        linkedList.addFirst(name);
    }
    public T top() {
        //取得串行第一个元素
        return linkedList.getFirst();
    }
    public T pop() {
        //移出第一个元素
        return linkedList.removeFirst();
    }
    public boolean isEmpty() {
        //串行是否为空
        return linkedList.isEmpty();
    }
    public static void main(String[] args) {
    	GenericStack<String> sstack=new GenericStack<String>();
    	sstack.push("first");
    	sstack.push("second");
    	sstack.push("third");
    	
    	while(!sstack.isEmpty()){
    		System.out.println(sstack.pop());
    	}    	
    }
}
