# Rice Cooker

## Description

Rice Cooker in Go is a project that simulates the functioning of a rice cooker. It has three functions that you can use: a function to boil water, a function to cook rice, and a function to simply heat food.

> I have used the linter and code style settings.

For Visual Studio:

> 1.  Linter : [golangci-lint](https://golangci-lint.run/)
> 2.  Code Style : [`gofmt`](https://dart.dev/guides/language/effective-dart/style)

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/hei-school/cc-d4-rice-cooker-ci-Vohizy
   cd cc-d4-rice-cooker-ci-Vohizy
   git checkout feature/Go
   ```

2. Install dependencies golangci-lint:

   ```bash
   go install github.com/golangci/golangci-lint/cmd/golangci-lint@v1.41.1
   ```

## Usage

You will run the code, and it will prompt you to make a choice. You only need to enter the number corresponding to your choice. If it asks you to enter a temperature and cooking duration, you should enter a number, not a letter, and avoid using decimal numbers.

### 1. Linting and Formatting:

Use the following command to run golangci-lint with formatting (--fix to perform automatic corrections) :

```bash
golangci-lint run --fix
```

### 2. Code Style

For code style, gofmt is often used to format Go code according to official style conventions

```bash
gofmt -w .
```
