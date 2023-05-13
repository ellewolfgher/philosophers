<h1 align=center>
	<b>philosophers</b>
</h1>
<div align=center>
<img src=https://github.com/ellewolfgher/philosophers/blob/main/philosopher.png alt="42 Project Philosophers Badge"/>
</div>

---

<h2 align=center>
	 <i>42 - Project #9</i>
</h2>

<p align=center>
	In computer science, the dining philosopher’s problem is a classic approach to illustrate what concurrency and race conditions are, and further highlighting the necessity to understand synchronization issues and possible techniques for resolving them. It was simple yet complex little project to work on, that managed to gather everything we’ve seen so far on the 42 syllabus – pointers, processes, signals, complex types and so much more. We’ve never, indeed, thought philosophy could be so deadly – nor so fun.
</p>

---

<h4 align=center>New Concepts</h4>
<h3 align=center>Threads and Mutexes</h3>
<h2>
The project
</h2>

In this problem, a pre-determined number of philosophers eat together at the same table. Each philosopher has their own place at the table and there is only one fork available per philosopher. They will need to eat, sleep, think and start the process all over again… again and again.

<p align="center">
  <img src="https://user-images.githubusercontent.com/80178342/227601334-852baa9d-6748-4a44-9cf7-b3cc0f853061.png" />
</p>

The problem lies in the fact that in order to eat, a philosopher needs to grab - one at a time - two forks, one in each hand. Also, they must eat every few moments from the moment they sit by the table or from the moment they last ate (this is also pre-determined by the user). If not, they will die. 
This all may sound simple enough, but believe me… it isn’t.

How can we make each philosopher eat independently from everyone else?

How can we prevent each philosopher from immediately grabbing a fork, and completely blocking everyone else from picking the second, eventually leading all to their imminent deaths?

How can we make sure that no two philosophers are eating simultaneously with the same fork?

How can we monitor whoever dies of finishes eating first, further preventing the simulation from continue?

This is the core concept of the philosopher’s project.
