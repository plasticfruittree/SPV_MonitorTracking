# SPECIAL PURPOSE VEHICLE MONITORING AND TRACKING SOFTWARE
## 1.0 INTRODUCTION

### 1.1 BACKGROUND OF THE PROJECT

When working within IB, most of my daily headaches were waiting on files from the originator and public side of the bank. 
There is sometimes a large time-delay for getting the files into the private side. Assuming the files are for the correct
pool and information is up-to-date, the analyst will have to manually parse these file for necessary 

The files are mainly Excel files with multiple sheets that vary based on the originator. These worksheets contain 
time-series data that have metrics specific to the asset pool. Tha analyst would spend the bulk of their time update internal 
Excel files that monitor the specific pool and asset class. In addition, the analyst will have to refer to previous
quarterly, semi-annual, or annual reviews (more Excel files and Powerpoints) to track the changes.

The complexity and time-waste of tracking a specific pool comes from the multiple calculations for the same metrics, poor
documentation, and finding the raw source data. In my limited experience, poor documentation and asking/finding 
the previous person that covered the name is the most frustrating time sink of the role.

### 1.2 STATEMENT OF THE PROBLEM

#### Originator storing and reporting of data

Data is stored in an Excel workbook that is highly unstructured and difficult to parse. Each workbook usually contains
the assets within the pool and reported metrics. As the pool changes, the changes should be easy to track and report. 
This problem is amplified when the pool is revolving. Reliable and consistent access to raw data is crucial.

#### Warehouse (Balance Sheet), Conduit (Commercial Paper), or Structure Product Waterfall Calculation

These pools of either on the balance sheet of a financial institution or sold to third-part investors as a single security
or a structured product. The pool of assets is created with specific risk metrics, then assigned an initial value at the time.
This initial value is a 100% and other layers of the waterfall will take several basis points. Usually, loan servicers will take their
fee from the interest and principle cash inflow. These layers should be easily tracked and altered.

#### Tracking and Monitoring

Financial institutions, servicers, and originator should have a platform which allow each party to update and view each pool's changes. The financial
institution should then be able to pull the data and present the changes quickly and accurately without delays. This platform should
counter the downsides of emailing Excel files and presentations.

#### Financial Institutions 

Financial institutions have strict regulation. So from the point of software, the platform should only be used as a data retrieval tool with flexible
functions for their business and quantitative segments to internally analyze and develop their models for risk management and portfolio management.

### 1.3 OBJECTIVES WITH THIS PROJECT

The main aim of this project is to build a web application with dashboard to monitor multiple loans that can be used for specific groups within a vertical.
1. Build a web application with dashboard that monitors loans and pool of loans and allows the servicer to update the pool 
2. Build the backend to calculate the waterfall calculations
3. Build the functionality for pulling data for the financial institution side

### 1.4  INITIAL PROJECT QUESTION 
1. What languages that fulfills the objectives and easily to implement?
2. How should MySQL be setup to support the project?
3. How do build an API to provide functionalities to the financial institutions?

### 1.5 SIGNIFICANCE OF THE PROJECT

This platform will remove the bottlenecks of Excel files. It makes monitoring and altering pools more easily while alerting all parties. The platform is profitable
since it value add for all parties.  

[How a loan pool works](https://docs.oracle.com/cd/E86273_01/html/SZ/SZ02_Overview.htm)

### 1.7 SCOPE OF THE PROJECT

This is an educational project to learning different technologies so getting MVC for each objective. Oracle FlexCub has a similar product. 

## 2.0 SETTING UP A MYSQL DATABASE