#include <stdio.h>

       int main() 
        {

    int totalCustomers;
    printf("Enter total number of customers: ");
    scanf("%d", &totalCustomers);

    int count = 1, totalRoomsBooked = 0, first = 1;
    float totalRevenue = 0, highest = 0, lowest = 0;

    while (count <= totalCustomers) {

        char name[50], bf, wifi, gym;
        int roomType, days;
        float roomRate = 0, base = 0, add = 0, sub = 0, disc = 0, gst = 0, final = 0;

        printf("\nCustomer %d\n", count);
  
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter room type (1-Deluxe, 2-Super Deluxe, 3-Suite): ");
        scanf("%d", &roomType);

        printf("Enter number of days: ");
        scanf("%d", &days);

        if (roomType == 1) roomRate = 2500;
        else if (roomType == 2) roomRate = 4000;
        else if (roomType == 3) roomRate = 6000;

        base = roomRate * days;

        printf("Breakfast (Y/N): ");
        scanf(" %c", &bf);

        if (bf == 'Y' || bf == 'y') add += 300 * days;

        printf("Wi-Fi (Y/N): ");
        scanf(" %c", &wifi);

        if (wifi == 'Y' || wifi == 'y') add += 100 * days;

        printf("Gym Access (Y/N): ");
        scanf(" %c", &gym);

        if (gym == 'Y' || gym == 'y') add += 200 * days;

        sub = base + add;

        if (sub > 10000) disc = sub * 0.10;

        sub -= disc;
        gst = sub * 0.12;
        final = sub + gst;

        printf("\nBase Fare: ₹%.0f\n", base);
         printf("Additional Services: ₹%.0f\n", add);
          printf("Subtotal: ₹%.0f\n", sub);
           printf("Discount: ₹%.0f\n", disc);
            printf("GST (12 percent): ₹%.0f\n", gst);
             printf("Final Bill: ₹%.0f\n", final);

        totalRoomsBooked++;
        totalRevenue += final;

        if (first) {
            highest = final;
            lowest = final;
            first = 0;
        } else {
            if (final > highest) highest = final;
            if (final < lowest) lowest = final;
        }

        count++;
    }

        printf("\n==Hotel Summary==\n");
          printf("Total Rooms Booked: %d\n", totalRoomsBooked);
           printf("Total Revenue: ₹%.0f\n", totalRevenue);
            printf("Highest Bill: ₹%.0f\n", highest);
             printf("Lowest Bill: ₹%.0f\n", lowest);
              printf("==========================\n");

          return 0;
                        }
