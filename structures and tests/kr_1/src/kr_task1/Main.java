package kr_task1;

public class Main {
	public static void main(String[] args) {
			char test1[] = {'a', 'b', 'c'};
			char test2[] = {'c'};
			char test3[] = {'a', 'b', 'a'};
			char test4[] = {'a', 'b', 'a', 'c'};
			char test5[] = {'a', 'a'};
			char test6[] = null;
			char test7[] = {'c','a', 'b', 'a'};
			assert(isUnique(test1));
			assert(isUnique(test2));
			assert(isUnique(test3) == false);
			assert(isUnique(test4) == false);
			assert(isUnique(test5) == false);
			assert(isUnique(test6) == false);
			assert(isUnique(test7) == false);
			System.out.print("All correct!");
			
	}
	private static boolean isUnique(char str[]){
		if(str == null){
			return false;
		}
		for(int i = 0; i < str.length - 1; i++){
			for(int j = i + 1; j < str.length; j++ ){
				if(str[i] == str[j]){
					return false;
				}
			}
		}
		return true;
	}
}
