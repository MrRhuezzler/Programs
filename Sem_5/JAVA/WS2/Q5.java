class LongStringLength {
    public static int[] ColumnMax(String[][] array){
        int[] max = new int[array.length];
        for(int i = 0; i < array.length; i++){
            max[i] = array[i][0].length();
            for(int j = 1; j < array[i].length; j++){
                if(array[i][j].length() > max[i]){
                    max[i] = array[i][j].length();
                }
            }
        }
        return max;
    }
}

public class Q5 {
    public static void main(String[] args) {
        String[][] a = {{"help", "ok", "city lights"},
                        {"elvisLives", "hello", "punch-out"},
                        {"hurrah", "humptydumpty", "123"}};
        int[] max = LongStringLength.ColumnMax(a);
        for(int i = 0; i < max.length; i++){
            System.out.print(max[i] + ", ");
        }
        System.out.println();
    }
}