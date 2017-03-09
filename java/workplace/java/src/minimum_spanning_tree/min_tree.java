package minimum_spanning_tree;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class min_tree {

	public static void main(String[] args) {
		/*
		 * 输入6 10 1 2 6 1 3 1 1 4 5 2 3 5 2 5 3 3 4 5 3 5 6 3 6 4 4 6 2 5 6 6
		 */
		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);
		int point_num = cin.nextInt();
		int edge_num = cin.nextInt();
		int[] edges = new int[2 * edge_num];
		int[] weights = new int[edge_num];
		for (int i = 0; i < edge_num; i++) {
			edges[2 * i] = cin.nextInt() - 1;
			edges[2 * i + 1] = cin.nextInt() - 1;
			weights[i] = cin.nextInt();
		}
		int[][] matrix = ChangeToMatrix(point_num, edge_num, edges, weights);

		System.out.println(getminweight(point_num, matrix));
	}

	// 构造邻接矩阵
	public static int[][] ChangeToMatrix(int point_num, int edge_num, int[] edges, int[] weight) {
		int[][] matrix = new int[point_num][point_num];
		for (int i = 0; i < edge_num; i++) {
			int m = edges[2 * i];
			int n = edges[2 * i + 1];
			matrix[m][n] = weight[i];
		}
		return matrix;
	}

	// 对二位数组的一组行列进行遍历找出最小权值及对应行列
	public static int[] findminweight(int[] key, int point_num, int[][] matrix) {
		int[] temp = new int[2];
		int temp_weight = 100, temp_line = 0, temp_key = 0;
		for (int k = 0; k < key.length; k++) {
			for (int i = 0; i < point_num; i++) {
				if (matrix[i][key[k]] > 0) {
					if (matrix[i][key[k]] < temp_weight) {
						temp_weight = matrix[i][key[k]];
						temp_line = i;
						temp_key = k;
					}
				}
				if (matrix[key[k]][i] > 0) {
					if (matrix[key[k]][i] < temp_weight) {
						temp_weight = matrix[key[k]][i];
						temp_line = i;
						temp_key = k;
					}
				}
			}
		}
		matrix[key[temp_key]][temp_line] = 0;
		matrix[temp_line][key[temp_key]] = 0;
		temp[0] = temp_weight;
		temp[1] = temp_line;
		return temp;
	}

	// 获得最小生成树权重之和
	public static int getminweight(int point_num, int[][] matrix) {
		Set<Integer> points = new HashSet<Integer>();
		int min_weight = 0;
		points.add(0);
		// 当集合中节点数目小鱼无向图节点数时，进行循环
		while (points.size() < point_num) {
			int[] points_array = new int[points.size()];
			int[] temp = new int[2];
			int num = 0;
			for (int point : points) {
				points_array[num] = point;
				num++;
			}

			temp = findminweight(points_array, point_num, matrix);

			// 输出矩阵
			// System.out.println();
			// for(int i=0;i<point_num;i++){
			// for(int j=0;j<point_num;j++){
			// System.out.print(matrix[i][j]+ " ");
			// }
			// System.out.println();
			// }
			// System.out.println();

			// 如果集合不包含该节点则添加该节点
			if (!points.contains(temp[1])) {
				points.add(temp[1]);
				min_weight = min_weight + temp[0];
			}
		}
		return min_weight;
	}
}
