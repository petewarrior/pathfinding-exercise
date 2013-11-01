#include <stdio.h>

/*
S





F
*/

int pindah_ke(int node, int jalur[][50], int best_so_far[], int jalur_sekarang[], int current_length);
int best_length = -1; // global variable

int main() 
{
	int solusi[1000];
	int jalur_sekarang[1000];
	
	int jalur[1000][50] = {
		{1, 2}, // 0
		{3, 4}, // 1
		{5, 7}, // 2
		{1, 6}, // 3
		{1}, 	// 4
		{2, 7, 8}, // 5
		{3, 8}, // 6
		{2, 5}, // 7
		{} // 8
	};
	pindah_ke(0, jalur, solusi, jalur_sekarang, 0);
}

int pindah_ke(int node, int jalur[][50], int best_so_far[], int jalur_sekarang[], int current_length) {
	jalur_sekarang[current_length] = node;
	printf("node saat ini: %d\n", node);
	current_length ++;
	
	printf("Jalur saat ini: ");
	int i;
	for(i = 0; i < current_length; i++) {
		printf("%d ", jalur_sekarang[i]);
	}
	printf("\n");
	
	if(node == 8) {
		if(best_length == -1|| best_length > current_length) {
			best_length = current_length;
			
			for(i = 1; i < 1000; i ++) {
				if(jalur_sekarang[i] != 0) best_so_far[i] = jalur_sekarang[i];
				else best_so_far[i] = 0;
			}
		}
		printf("\n* sampai dalam %d langkah *\nLangkah terpendek sejauh ini: ", current_length);
		printf("0 ");
		
		for(i = 1; best_so_far[i] != 0; i++) {
			printf("%d ", best_so_far[i]);
		}
		printf("\n\n");
	} else {
		int node_ke = 0;
		while(jalur[node][node_ke] != 0) {
			int jscheck = 0;
			uint skip = 0;
			printf("check jalur dari %d ke %d", node, jalur[node][node_ke]);
			while(jalur_sekarang[jscheck] != 0 || jscheck == 0) {
				
				if(jalur_sekarang[jscheck] == jalur[node][node_ke]) {
					skip = 1;
					printf(" (sudah ada)");
					jscheck = 0;	
					break;
				}
				
				jscheck ++;
			}
			printf("\n");
			if(skip == 1) { 
				printf("skip node %d\n", jalur[node][node_ke]);
				node_ke ++; 
				continue; 
			}
			pindah_ke(jalur[node][node_ke], jalur, best_so_far, jalur_sekarang, current_length);
			jalur_sekarang[current_length] = 0;
			node_ke ++;
		}
	}
	
}