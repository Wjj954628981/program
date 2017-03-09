package Collection;

import java.util.*;

public class StringStack {
    private LinkedList<String> linkedList;
    public StringStack() {
        linkedList = new LinkedList<String>();
    }
    public void push(String name) {
        //��Ԫ�ؼ��봮��ǰ��
        linkedList.addFirst(name);
    }
    public String top() {
        //ȡ�ô��е�һ��Ԫ��
        return linkedList.getFirst();
    }
    public String pop() {
        //�Ƴ���һ��Ԫ��
        return linkedList.removeFirst();
    }
    public boolean isEmpty() {
        //�����Ƿ�Ϊ��
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
