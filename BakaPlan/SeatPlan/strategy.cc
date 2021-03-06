#include "strategy.h"

Strategy :: Strategy()
{
    total_seats = total_students = total_group_seats = 0;
}

void Strategy :: totalSeats(int strategy)
{
    for(i = 0; i < total_centres; i++)
    {
        for(j = 0; j < total_rooms[i]; j++)
        {
            room_size[i][j] = rows[i][j] * cols[i][j];
            total_seats += room_size[i][j];
            total_group_seats += room_size[i][j] / strategy;
        }
    }
}

void Strategy :: totalStudents()
{
    for(i = 0; i < total_code; i++)
    {
        total_students += sub_totalrno[i];
    }
}

void Strategy :: totalGroupStudents(int strategy)
{
    if(strategy == 5)
        strategy = 1;
    s = 0;
    for(i = 0; i < total_code; i++)
    {
        temp[i] = sub_totalrno[i];
        index_value[i] = 0;
    }
//    cout << "total code " << total_code << endl;
    
    for(i = 0; i < strategy; i++)
    {
        group_student_size[i] = 0;
    }
    
    sort(temp, temp + total_code);
    
    for(i = 0; i < total_code; i++)
    {
        for(j = 0; j < total_code; j++)
        {
            if(temp[j] == sub_totalrno[i])
            {
                if(index_value[j] == 0)
                {
                    index_value[j] = i;
                    break;
                }
                
            }
        }
    }
    
    for(i = 0; i < total_code; i++)
    {
        if(s == strategy)
            s = 0;
        group_student_size[s] += sub_totalrno[index_value[i]];
        s++;
               
    }
    sort(group_student_size, group_student_size + strategy);
}

void Strategy :: groupCondition(int strategy)
{
    if(group_student_size[strategy-1] > total_group_seats)
    {
        int extra = (group_student_size[strategy-1] - total_group_seats);
        extra = extra * strategy;
        outfile << "\t condition invalid" << endl
                << "\t Add " << extra << " more seats." << endl;
        
        outfile.close();    
    }
    else
    {
        outfile << "Y" << endl;
        outfile << "\t condition is valid" << endl;
        outfile.close();
        seatingPlan(strategy);
        showSeatPlan();
//        Report :: Main();
    }
}

void Strategy :: checkValidation(int strategy)
{
    outfile.open(Validation_out);
    
    totalSeats(strategy);
    totalStudents();
    totalGroupStudents(strategy);
    
    outfile << "\n\t Total Seats = " << total_seats << endl
            << "\t Total Students = " << total_students << endl
            << "\t Total Group Seats = " << total_group_seats << endl
            << "\t Max Group Students = " << group_student_size[strategy-1] << endl;
    
    // Showing values while console
//    cout << "\n\t Total Seats = " << total_seats << endl
//         << "\t Total Students = " << total_students << endl
//         << "\t Total Group Seats = " << total_group_seats << endl
//         << "\t Max Group Students = " << group_student_size[strategy-1] << endl;
//    
    if(total_seats < total_students)
    {
        outfile << "\t Add More rooms!" << endl;
//        cout << "\t Add More rooms!" << endl;
        outfile.close();
    }
        
    else
        groupCondition(strategy);
        
    //outfile.close();
}
        
void Strategy :: chooseStrategy()
{
    int choice;
    infile.open(Input_Strategy);
    infile >> strategy_choice;    
    infile.close();
    
    if(strategy_choice == "1")//"Continual Strategy")
        choice = 1;
    if(strategy_choice == "2")//"Strategy 2")
        choice = 2;
    if(strategy_choice == "3")//"Strategy 3")
        choice = 3;
    if(strategy_choice == "4")//"Strategy 4")
        choice = 4;
    if(strategy_choice == "5")//"Serpentine Strategy")
        choice = 5;
        
    checkValidation(choice);
}

void Strategy :: Main()
{
    readSubjectWiseRollNo(Subjectwise_Rollno_out);
    readRoomDetails(Input_Rooms);
    chooseStrategy();
}
