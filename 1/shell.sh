#Write a program to implement an address book with options given below:
#a) Create address book. b) View address book. c) Insert a record. d) Delete a record.
#e) Modify a record. f) Exit.

function insert()                   #function to insert a record
{
    echo
    echo "Enter the Name : "
    read name
    echo
    echo "Enter the Phone number : "
    read phno                  #accepting details of record
    echo
    echo "Enter the Address : "
    read addr
    echo "$1 | $name | $phno | $addr" >> $filename    #storing record
    echo "Record has been Inserted..."
    return
}

modify()                      #function to modify a record
{
    grep -v -w $1 $filename > $filename2
    echo "Enter the Name : "
    read name
    echo "Enter the New Phone number : "
    read phno
    echo "Enter the New Address"
    read addr
    echo "$1 | $name | $phno | $addr" >> $filename2
    echo "Record has been Modified..."
    cat $filename2 > $filename
    return
}

delete ()                   #function to delete a record
{
    grep -v -w $1 $filename > $filename2
    echo "Record has been deleted..."
    cat $filename2 > $filename
    return
}

clear
echo "Enter the Filename : "
read filename
filename2=temp.db           #accepting file name

if [ -f $filename ]         #checking if file exists
then
    echo "File already Exists..."
else
    echo "SNo | Name | Phone | Address" > $filename
    echo "New File has been Created..."
fi


for(( ; ; ))
do
echo "1. Insert a Record."
echo "2. View address book."
echo "3. Search a Record."      #displaying menu
echo "4. Modify a Record."
echo "5. Delete a Record."
echo "6. Exit..."
echo "Enter your Choice : "
read ch

case $ch in
1)
    while [ true ]
    do
    echo "Enter a Serial No. : "
    read roll

    if (grep -w $roll $filename)   #checking if exists
    then
        echo "Roll num already exists..."
    else
        insert $roll
        break
    fi
    done
    ;;

2)
    cat $filename;;               #displaying the file

3)
    echo "Enter serial num to be searched"
    read roll
    if (grep -w $roll $filename)
    then
        echo
    else
        echo "No such Record..."
    fi
    ;;

4)
    echo "Enter serial num to be modified"
    read roll
    if (grep -w $roll $filename)
    then
        modify $roll           #function call
    else
        echo "No such Record..."
    fi
    ;;
5)
    echo "Enter serial num to be deleted"
    read roll
    if(grep -w $roll $filename)
    then
        delete $roll
    else
        echo "No such Record..."
    fi
    ;;
6)
    exit
    ;;
*)
    echo "Invalid Choice..."
    ;;
esac
done