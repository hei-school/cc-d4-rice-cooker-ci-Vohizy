# Rice Cooker

## Description

Rice Cooker in C++ is a project that simulates the functioning of a rice cooker. It has three functions that you can use: a function to boil water, a function to cook rice, and a function to simply heat food.

> I have used the linter and code style settings.

For Visual Studio:

> 1.  Linter : `Intégré à Roslyn` (partie intégrante de Visual Studio)
> 2.  Code Style : [`Suivre les recommandations de Microsoft`](https://docs.microsoft.com/en-us/dotnet/csharp/programming-guide/inside-a-program/coding-conventions)

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/hei-school/cc-d4-rice-cooker-ci-Vohizy
   cd cc-d4-rice-cooker-ci-Vohizy
   git checkout feature/C#
   ```

2. Install dependencies for the test:

   ```bash
   dotnet add package xunit
   ```

   and

   ```bash
   dotnet add package xunit.runner.console
   ```

## Usage

You will run the code, and it will prompt you to make a choice. You only need to enter the number corresponding to your choice. If it asks you to enter a temperature and cooking duration, enter a number without using letters or decimal numbers.

### Run Test

```bash
dotnet test
```
