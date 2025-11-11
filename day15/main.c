#include <stdio.h>

#define max_students 10

void print_separator() 
    {
    printf("==================\n");
    }

      int main()
    {
         int marks[max_students];
          int num_students;
           int i;

       int total_marks = 0;
        int highest_mark = -1;
          int lowest_mark = 101;
           int passed_students = 0;
            int failed_students = 0;

               float average_marks;

    int A_plus = 0;
    int A = 0;
    int B_plus = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int Fail = 0;

    print_separator();
    printf("Student Performance Analyzer\n");
    print_separator();

    do {
        printf("Enter the number of students (max %d): ",max_students);
        if (scanf("%d", &num_students) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); 
            num_students = 0;
        } else if (num_students <= 0 || num_students >max_students) {
            printf("Number of students must be between 1 and %d.\n",max_students);
        }
    } while (num_students <= 0 || num_students >max_students);

    for (i = 0; i < num_students; i++) {
        do {
            printf("Enter mark for Student %d (0-100): ", i + 1);
            if (scanf("%d", &marks[i]) != 1) {
                printf("Invalid input. Please enter a number.\n");
                while(getchar() != '\n'); 
                marks[i] = -1;
            } else if (marks[i] < 0 || marks[i] > 100) {
                printf("Mark must be between 0 and 100.\n");
            }
        } while (marks[i] < 0 || marks[i] > 100);
    }

    for (i = 0; i < num_students; i++) {
        int current_mark = marks[i];

        total_marks += current_mark;

        if (current_mark > highest_mark) {
            highest_mark = current_mark;
        }

        if (current_mark < lowest_mark) {
            lowest_mark = current_mark;
        }

        if (current_mark >= 50) {
            passed_students++;

            if (current_mark >= 90) {
                A_plus++;
            } else if (current_mark >= 80) {
                A++;
            } else if (current_mark >= 70) {
                B_plus++;
            } else if (current_mark >= 60) {
                B++;
            } else if (current_mark >= 50) {
                C++;
            } else {
                D++;
            }
        } else  {
            failed_students++;
            Fail++;
        }
    }
    
    average_marks = (float)total_marks / num_students;

    print_separator();
    printf("Result Summary\n");
    print_separator();

     
    for (i = 0; i < num_students; i++) {
        printf("Student %d: %d\n", i + 1, marks[i]);
    }
      print_separator();

     printf("Average Marks: %.2f\n", average_marks);
      printf("Highest Mark: %d\n", highest_mark);
       printf("Lowest Mark: %d\n", lowest_mark);
        printf("Total Passed Students: %d\n", passed_students);
         printf("Total Failed Students: %d\n", failed_students);

    print_separator();
     printf("Grade Distribution:\n");
      printf("A+: %d\n", A_plus);
       printf("A: %d\n", A);
        printf("B+: %d\n", B_plus);
         printf("B: %d\n", B);
          printf("C: %d\n", C);
           printf("D: %d\n", D);
            printf("Fail: %d\n", Fail);
             print_separator();

        return 0;
     }
