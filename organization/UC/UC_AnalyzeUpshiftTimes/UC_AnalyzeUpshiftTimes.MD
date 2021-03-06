# Use-Case Specification: Analyze Upshift Times
# Table of Contents
- [Analyze Upshift Times](#1-analyze-upshift-times)
    - [Brief Description](#11-brief-description)
    - [Screenshots](#12-screenshots)
- [Flow of Events](#2-flow-of-events)
    - [Basic Flow](#21-basic-flow)
    - [Alternative Flows](#22-alternative-flows)
- [Special Requirements](#3-special-requirements)
- [Preconditions](#4-preconditions)
- [Postconditions](#5-postconditions)

# 1. Analyze Upshift Times
## 1.1 Brief Description
The use case 'Analyze Upshift Times' determines the time it takes the driver to change to a higher gear. This obviously makes more sense in car with a manual transmission. Two different times will be calculated. The first on is the time the clutch was disengaged, which is the total time needed for the gear shift, as this is the time the car is not putting any power to the wheels. The other time just indicates how long the driver needed to get the transmission out of gear and back into the new gear.

## 1.2 Screenshots
For Screenshots look at the [UC See Analytics](../UC_SeeAnalytics/UC_SeeAnalytics.MD).

# 2. Flow of Events
## 2.1 Basic Flow
![Analyze Upshift Times UML](UML.png "UML")

## 2.2 Alternative Flows
n/a

# 3. Special Requirements
n/a

# 4. Preconditions
To calculate the upshift times an input data stream is necessary.

# 5. Postconditions
n/a

# 6. Function Points
For calculating the Function Points we used the tool on [this](http://groups.umd.umich.edu/cis/course.des/cis375/projects/fp99/main.html) website.

For the following Input we got a score of: **62.4 Function Points**.
This results in an estimation of *9:43h* for this Use Case.

![Analyze Upshift Times Input](AnalyzeUpshiftTimesInput.png "Function Point Calculation Input")
![Analyze Upshift Times Questions](AnalyzeUpshiftTimesQuestions.jpg "Function Point Calculation Questions")
