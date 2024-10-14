#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONTHS 12

// Define Functions
void monthly_sales_report(const char months[][10], float sales[]);
void sales_summary_report(float sales[]);
void six_month_moving_average(const char months[][10], float sales[]);
void sort_sales_report(const char months[][10], float sales[]);

int main() {
    // Define the months array
    const char months[MONTHS][10] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    // Define the sales array
    float sales[MONTHS] = {0.0};

    // Open the input file
    FILE *file_ptr = fopen("sales.txt", "r");
    if (file_ptr == NULL) {
        printf("Error: Could not open file 'sales.txt'.\n");
        return 1;
    }

    // Read sales data from the file into the sales array
    for (int i = 0; i < MONTHS; i++) {
        if (fscanf(file_ptr, "%f", &sales[i]) != 1) {
            printf("Error: Invalid data in file.\n");
            fclose(file_ptr);
            return 1;
        }
    }
    fclose(file_ptr); // Close the file

    // Generate reports
    monthly_sales_report(months, sales);
    sales_summary_report(sales);
    six_month_moving_average(months, sales);
    sort_sales_report(months, sales);

    return 0;
}

// Monthly Sales Report
void monthly_sales_report(const char months[][10], float sales[]) {
    printf("\nMonthly Sales Report:\n");
    printf("----------------------------\n");
    printf("Month        Sales\n");
    printf("----------------------------\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-12s %.2f\n", months[i], sales[i]);
    }
}

// Sales Summary Report (min, max, average)
void sales_summary_report(float sales[]) {
    float min = sales[0], max = sales[0], sum = 0.0;
    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) min = sales[i];
        if (sales[i] > max) max = sales[i];
        sum += sales[i];
    }
    float average = sum / MONTHS;

    printf("\nSales Summary Report:\n");
    printf("----------------------------\n");
    printf("Minimum Sales: %.2f\n", min);
    printf("Maximum Sales: %.2f\n", max);
    printf("Average Sales: %.2f\n", average);
}

// Six-Month Moving Average Report
void six_month_moving_average(const char months[][10], float sales[]) {
    printf("\nSix-Month Moving Average Report:\n");
    printf("----------------------------\n");
    for (int i = 0; i <= MONTHS - 6; i++) {
        float sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float average = sum / 6.0;
        printf("%-12s - %-12s: %.2f\n", months[i], months[i + 5], average);
    }
}

// Sales Report (Highest to Lowest)
void sort_sales_report(const char months[][10], float sales[]) {
    // Create copies of the sales and months arrays for sorting
    float sorted_sales[MONTHS];
    char sorted_months[MONTHS][10];

    for (int i = 0; i < MONTHS; i++) {
        sorted_sales[i] = sales[i];
        strcpy(sorted_months[i], months[i]);
    }

    // Sort the sales array in descending order using bubble sort
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (sorted_sales[j] < sorted_sales[j + 1]) {
                // Swap sales
                float temp_sales = sorted_sales[j];
                sorted_sales[j] = sorted_sales[j + 1];
                sorted_sales[j + 1] = temp_sales;

                // Swap corresponding months
                char temp_month[10];
                strcpy(temp_month, sorted_months[j]);
                strcpy(sorted_months[j], sorted_months[j + 1]);
                strcpy(sorted_months[j + 1], temp_month);
            }
        }
    }

    // Print the sorted sales report
    printf("\nSales Report (Highest to Lowest):\n");
    printf("----------------------------\n");
    printf("Month        Sales\n");
    printf("----------------------------\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-12s %.2f\n", sorted_months[i], sorted_sales[i]);
    }
}