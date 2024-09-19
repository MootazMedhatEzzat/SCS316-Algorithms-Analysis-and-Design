# SCS316-Algorithms-Analysis-and-Design

<div align="center">
  <table width="100%">
    <tr>
      <td colspan="2" align="center"><strong>{ Assignment 1: Algorithms Problems }</strong></td>
    </tr>
    <tr>
      <td align="left"><strong>Name</strong>: Mootaz Medhat Ezzat Abdelwahab</td>
      <td align="right"><strong>Id</strong>: 20206074</td>
    </tr>
    <tr>
      <td align="left"><strong>Program</strong>: Software Engineering</td>
      <td align="right"><strong>Group</strong>: B (S5)</td>
    </tr>
    <tr>
      <td align="center" colspan="2"><strong>Delivered To:</strong><br>DR. Zeinab Abd ElHaliem<br>TA. Dalia Maher Mohamed</td>
    </tr>
  </table>
</div>

---

## Assignment #1 (Deadline 17/11/2022)

Cairo University  
Faculty of Computers and Artificial Intelligence  
Algorithms Analysis and Design Course (Spring 2023) 

### 📝 Problems

#### 📊 Problem 1️⃣:
Let \( c \) represent the constant factor in the \( O(n) \) term.

- 🖋️ Write the recurrence relation.
- 🔍 Verify that the upper bound is \( O(n \log n) \) using the substitution method.

<div align="center">
  <img src="https://github.com/user-attachments/assets/76eebcf5-b561-4e63-a663-340e1468ffd7" alt="image">
</div>

#### 🌳 Problem 2️⃣:
Construct a recursion tree for the recurrence \( T(n) = 3T(n/4) + cn^2 \) and solve it using the substitution method.

#### 🧮 Problem 3️⃣:
Solve the following recurrence relation:
\[ T(0) = c1, \quad T(1) = c2, \quad T(n) = 2^k T(n/2^k) + (2^k − 1)c3 \]

#### ⚖️ Divide and Conquer Problems

##### ➗ Problem 4️⃣:
Given an array of \( n \) elements \( A[0: n-1] \) that may contain positive and negative numbers.

- 🔎 Find the contiguous subarray of numbers which has the largest sum.
- 🖋️ Write the recurrence relation and solve it.

##### ✖️ Problem 5️⃣:
- 🔎 Find the multiplication matrix of 2 square matrices \( A \) and \( B \) of size \( n*n \) each. 
- 🖋️ Write the recurrence relation and solve it.

##### ✈️ Problem 6️⃣:
We are given an array of \( n \) points in the plane, and the problem is to find out the closest pair of points in the array.

This problem arises in a number of applications. For example, in air-traffic control, you may want to monitor planes that come too close together, since this may indicate a possible collision.

Recall the following formula for distance between two points \( p \) and \( q \):
\[ \text{Euclidean distance } d(p, q) = \sqrt{(qx − px)^2 + (qy − py)^2} \]

- The brute force solution is \( O(n^2) \), compute the distance between each pair and return the smallest.
- 🎯 Find the smallest distance in \( O(n \log n) \) time using the Divide and Conquer strategy.

##### 🏆 Problem 7️⃣:
Consider an unsorted array with \( N \) number of elements and given number \( k \) value in range from 1 to \( N \); we have to find the \( k \)-th largest element in the best possible way which takes time complexity \( O(n) \).

**Example:**

- 📥 Input: \( K = 3 \), \( A[] = \{14, 5, 6, 12, 14, 8, 10, 6, 25\} \)  
  🖥️ Output: \( k \)-th largest element = 12

- 📥 Input: \( K = 5 \), \( A[] = \{18, 15, 3, 1, 2, 6, 2, 18, 16\} \)  
  🖥️ Output: \( k \)-th largest element = 3

##### 🔄 Problem 8️⃣:
Given an array of integers. Find the **Inversion Count** in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0. If an array is sorted in reverse order, then the inversion count is the maximum. Formally, two elements \( a[i] \) and \( a[j] \) form an inversion if \( a[i] > a[j] \) and \( i < j \).

**Examples:**

- 📥 Input: \( N = 5 \), \( arr[] = \{2, 4, 1, 3, 5\} \)  
  🖥️ Output: 3  
  📝 Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

- 📥 Input: \( N = 5 \), \( arr[] = \{2, 3, 4, 5, 6\} \)  
  🖥️ Output: 0  
  📝 Explanation: As the sequence is already sorted, so there is no inversion count.

- 📥 Input: \( N = 3 \), \( arr[] = \{10, 10, 10\} \)  
  🖥️ Output: 0  
  📝 Explanation: As all the elements of the array are the same, so there is no inversion count.

### 📤 Submission Instructions

- Please submit your solutions via **Google Classroom**.
- You should submit a zip file `(name this file with your id A1_STUDENT-ID.zip)`, put all files (codes) for each problem `(name code file p1, p2, .. etc)`.

### 🛠️ Programming Language and Development Tools Used

<table align="center" border="1" cellpadding="10">
  <thead>
    <tr>
      <th>Programming Language</th>
      <th>Development Tool</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center">
        <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" title="C++" alt="C++" width="40" height="40"/>
      </td>
      <td align="center">
        <img src="https://github.com/user-attachments/assets/1db36f07-698f-400f-bdd7-b3ad8f936f5d" title="Code::Blocks" alt="Code::Blocks" width="40" height="40"/>
      </td>
    </tr>
    <tr>
      <td align="center">
        C++
      </td>
      <td align="center">
        Code::Blocks IDE
      </td>
    </tr>
  </tbody>
</table>

---

## 💬 Let's Connect
Feel free to reach out to me if you'd like to collaborate on a project or discuss technology! As a Software Engineer, I'm always open to tackling new challenges, sharing knowledge, and growing through collaborative opportunities.

**Mootaz Medhat Ezzat Abdelwahab**  
🎓 Software Engineering Graduate | Faculty of Computers and Artificial Intelligence, Cairo University  

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/mootaz-medhat-ezzat-abdelwahab-377a60244)
