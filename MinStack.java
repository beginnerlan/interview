import java.util.EmptyStackException;
import java.util.Stack;

/**
 * 定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素，push和pop的时间复杂度都是O（1）
 */
public class MinStack {
	private Stack<Integer> elements;
	private Stack<Integer> minimums;
	
	public MinStack(Stack<Integer> elements, Stack<Integer> minimums) {
		this.elements = elements;
		this.minimums = minimums;
	}
	
	public void push(int item) {
		elements.push(item);
		if(minimums.empty() || item <= minimums.peek()) {
			minimums.push(item);
		}
	}
	
	public int pop() {
		if(elements.empty())
			throw new EmptyStackException();
		if(elements.peek() == minimums.peek())
			minimums.pop();
		return elements.pop();
	}
	
	public int getMinimum() {
		return minimums.peek();
	}
	
	public static void main(String[] args) {
		Stack<Integer> elements = new Stack<Integer>();
		Stack<Integer> minimums = new Stack<Integer>();
		MinStack stack = new MinStack(elements, minimums);
		stack.push(2);
		stack.push(6);
		stack.push(4);
		stack.push(1);
		stack.push(5);
		System.out.println(stack.getMinimum());
		stack.pop();
		stack.pop();
		System.out.println(stack.getMinimum());
	}
}