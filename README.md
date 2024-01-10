# VOTELITE: MINI-VOTING SYSTEM

## Table of Contents

- [Project Overview](#project-overview)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [Authors](#authors)

## <a id="project-overview"></a>Project Overview 
VoteLite: Mini-Voting System is a console-based application implemented in C to streamline the process of conducting elections. The system manages user registrations, tracks candidates, and ensures the secure and organized handling of votes. It features an admin panel for election setup, user authentication, and result analysis, as well as a student panel for casting votes. The project utilizes file handling to save and load election information, candidate details, and voting status, ensuring the integrity and continuity of the election process. The code includes error-handling mechanisms to address issues related to invalid user input, banned users, and vote deletion. VoteLite provides a user-friendly interface, allowing administrators to initiate and continue elections, delete illegal votes, ban/unban users, and view election results.

## KEY FEATURES 
1. Election Management
* Admins can initiate, load, and manage elections, controlling the setup parameters such as year, branch code, total voters, and candidates.
* The system ensures secure handling of election data and supports the continuation of previous elections.
2. User Authentication and Admin Panel
* Admins can log in to an exclusive admin panel using a predefined username and password (Admin, votewisely).
* The admin panel provides options to start a new election, continue a previous election, delete illegal votes, ban user IDs, and view election results.
3. Student Voting Panel
* Students can cast votes by entering their 14-character user ID, which includes the year, branch code, and roll number.
* The system validates user IDs, checks for banned IDs, and prevents duplicate voting. It updates candidate votes and records the voting status.
4. File Handling
* The program utilizes file handling to save and load critical election information, candidate details, and voting status.
* Files are organized to maintain data integrity, including the creation of individual files for each candidate and a central file for overall election information.
5. Error Handling and User-Friendly Interface
* The system includes error-handling mechanisms to address invalid user input, banned users, and vote deletion.
* The CLI-based interface ensures simplicity for both administrators and students, guiding them through the voting process and result analysis.

## <a id="installation"></a>Installation 
 Clone the repository
  ```bash
  git clone https://github.com/yldevier/Event-Ticketing-System.git
```
Compile the Source Code:
``` bash
gcc main.c -o main
```
## <a id="usage"></a>Usage
Execute the Program by running the executable
```bash
./main
```
## <a id="contributing"></a>Contributing
If you want to improve this project and contribute, here are the steps below.
1. Fork the repository
2. Create a new branch for your feature (`git checkout -b feature/new-feature`).
3. Commit your changes (`git commit -m "commit message"`).
4. Push to the branch
5. Open a pull request

## <a id="authors"></a> :pen: Authors and Contributors 
* **Mark Peña** [@MakkuHuqueriza]
* **Trixie Organiza** [@pixie1013]
* **Angela Masong** [@angelakim19]
* **Carl Suello** [@v1cXcarlito]
