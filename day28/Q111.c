#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 20

struct Seat {
    int seat_id;
    char row;
    int seat_num;
    float price;
    int is_booked;
    char customer_name[50];
};

struct TicketSystem {
    struct Seat seats[TOTAL_SEATS];
};

void initialize_seats(struct TicketSystem *ts) {
    char rows[] = {'A', 'B', 'C', 'D'};
    int index = 0;
    
    for (int r = 0; r < 4; r++) {
        for (int s = 1; s <= 5; s++) {
            ts->seats[index].seat_id = index + 1;
            ts->seats[index].row = rows[r];
            ts->seats[index].seat_num = s;
            
            if (rows[r] == 'A' || rows[r] == 'B') {
                ts->seats[index].price = 15.00; 
            } else {
                ts->seats[index].price = 10.00; 
            }
            
            ts->seats[index].is_booked = 0;
            strcpy(ts->seats[index].customer_name, "");
            index++;
        }
    }
}

void display_seats(struct TicketSystem *ts) {
    printf("\n--- Seat Availability Map ---\n");
    printf("Screen This Way \n");
    printf("-----------------------------------\n");
    
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("[%c%d: ", ts->seats[i].row, ts->seats[i].seat_num);
        if (ts->seats[i].is_booked) {
            printf("🔴] ");
        } else {
            printf("$%.0f🟢] ", ts->seats[i].price);
        }
        
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("-----------------------------------\n");
    printf("🟢 = Available | 🔴 = Booked\n");
}

void book_ticket(struct TicketSystem *ts) {
    printf("\n--- Book a Ticket ---\n");
    display_seats(ts);
    
    char row_choice;
    int num_choice;
    
    printf("\nEnter Row Letter (A-D): ");
    scanf(" %c", &row_choice);
    printf("Enter Seat Number (1-5): ");
    scanf("%d", &num_choice);
    
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (ts->seats[i].row == row_choice && ts->seats[i].seat_num == num_choice) {
            if (ts->seats[i].is_booked) {
                printf("❌ Error: Seat %c%d is already reserved!\n", row_choice, num_choice);
                return;
            }
            
            printf("Enter Customer Name: ");
            scanf(" %[^\n]s", ts->seats[i].customer_name);
            
            ts->seats[i].is_booked = 1;
            printf("\n=====================================\n");
            printf("        TICKET BOOKED SUCCESSFULLY   \n");
            printf("=====================================\n");
            printf("Passenger: %s\n", ts->seats[i].customer_name);
            printf("Seat:      %c%d\n", ts->seats[i].row, ts->seats[i].seat_num);
            printf("Total Paid: $%.2f\n", ts->seats[i].price);
            printf("=====================================\n");
            return;
        }
    }
    printf("❌ Error: Invalid seat selection.\n");
}

void cancel_ticket(struct TicketSystem *ts) {
    printf("\n--- Cancel a Ticket ---\n");
    char row_choice;
    int num_choice;
    
    printf("Enter Row Letter (A-D) of your seat: ");
    scanf(" %c", &row_choice);
    printf("Enter Seat Number (1-5) of your seat: ");
    scanf("%d", &num_choice);
    
    for (int i = 0; i < TOTAL_SEATS; i++) {
        if (ts->seats[i].row == row_choice && ts->seats[i].seat_num == num_choice) {
            if (!ts->seats[i].is_booked) {
                printf("⚠️ Alert: This seat is not currently booked.\n");
                return;
            }
            
            ts->seats[i].is_booked = 0;
            printf("🗑️ Booking for seat %c%d (under name '%s') has been canceled.\n", 
                   row_choice, num_choice, ts->seats[i].customer_name);
            strcpy(ts->seats[i].customer_name, "");
            return;
        }
    }
    printf("❌ Error: Invalid seat selection.\n");
}

int main() {
    struct TicketSystem ts;
    initialize_seats(&ts);
    int choice;

    while (1) {
        printf("\n=================================\n");
        printf("      TICKET BOOKING SYSTEM      \n");
        printf("=================================\n");
        printf("1. View Seating Chart\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Reservation\n");
        printf("4. Exit\n");
        printf("\nEnter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid input! Cleaning buffer...\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (choice == 1) {
            display_seats(&ts);
        } else if (choice == 2) {
            book_ticket(&ts);
        } else if (choice == 3) {
            cancel_ticket(&ts);
        } else if (choice == 4) {
            printf("\nExiting Ticket System. Goodbye!\n");
            break;
        } else {
            printf("❌ Invalid choice! Please select 1-4.\n");
        }
    }

    return 0;
}