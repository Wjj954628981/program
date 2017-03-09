package Collection;

import java.util.*;

public class GenericStack<T>{
    private LinkedList<T> linkedList;
    public GenericStack() {
        linkedList = new LinkedList<T>();
    }
    public void push(T name) {
        //��Ԫ�ؼ��봮��ǰ��
        linkedList.addFirst(name);
    }
    public T top() {
        //ȡ�ô��е�һ��Ԫ��
        return linkedList.getFirst();
    }
    public T pop() {
        //�Ƴ���һ��Ԫ��
        return linkedList.removeFirst();
    }
    public boolean isEmpty() {
        //�����Ƿ�Ϊ��
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
