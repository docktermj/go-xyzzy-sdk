# go-xyzzy-sdk

## Development

### Clone repository

1. Set these environment variable values:

    ```console
    export GIT_ACCOUNT=docktermj
    export GIT_REPOSITORY=go-xyzzy-sdk
    export GIT_ACCOUNT_DIR=~/${GIT_ACCOUNT}.git
    export GIT_REPOSITORY_DIR="${GIT_ACCOUNT_DIR}/${GIT_REPOSITORY}"
    ```

1. Follow steps in [clone-repository](https://github.com/docktermj/KnowledgeBase/blob/master/HowTo/clone-repository.md) to install the Git repository.

### Build

1. Build code.
   Example:

    ```console
    cd ${GIT_REPOSITORY_DIR}
    make build
    ```

### Run

1. Build code.
   Example:

    ```console
    cd ${GIT_REPOSITORY_DIR}/target/linux
    ./go-hello-xyzzy-dynamic
    ```

## References
