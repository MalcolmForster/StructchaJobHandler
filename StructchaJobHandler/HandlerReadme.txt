Structcha Handler is a software which allows clients to upload Structcha analysis files to the Structcha server to be processed.

Parts of StructchaHandler:


[JobChecker is not part of StructchaHandler as such, but important to note here to explain the flow through the software]
0. JobChecker^
    - Checks if the job can be started, ie no errors and reports back to the client with feedback.
    - These files are currently planned to be .scan (StructCha ANalysis) files, which are binary encoded files that transfer all the information needed for analysis on the server.
    - If all is ok, stores the job as ToDo in the corresponding databases.

1. JobFinder
    - Checks if any new jobs are to be started and if there is capacity on Structcha Servers to run the job.
    - List of jobs are kept in a database, which links a job code (and other information) to a job file (and all required files for the analysis).

2. JobStarter
    - Checks that the job can be started and then starts the job.

3. JobStatus
    - While job is running, gets status and reports to user every so often. Can set the job status once completed or paused/cancelled.

4. JobResults
    - When a job is completed, JobResults is able to send result data to the client when requested.

