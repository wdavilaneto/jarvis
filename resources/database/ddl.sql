create table activation_function (
    id integer primary key,
    name text not null
);

create table neural_network (
    id integer PRIMARY KEY,
    name text not null ,
    num_layers integer not null,
    num_input integer not null ,
    num_hidden integer not null ,
    num_output integer not null,
    desired_error numeric not null,
    max_epochs integer ,
    epochs_between_reports integer,
    activation_hidden integer REFERENCES activation_function(id) ,
    activation_output integer  REFERENCES activation_function(id) ,
    trained text
);
-- ALTER TABLE neural_network ADD trained text;

--drop table corpus;
create table corpus (
    id integer PRIMARY KEY,
    name text not null unique,
    language TEXT
);

drop table word;
create table word (
    id integer primary key,
    corpus_id integer not null references corpus(id),
    name text not null unique,
    total integer not null default 0,
    hits_on_documents integer not null default 0,
    is_stop boolean default false
);

drop table document;
create table document (
    id integer PRIMARY KEY,
    parent_id integer references document(id),
    corpus_id integer not null references corpus(id),
    ref_id integer default 0,
    words_json text ,
    last_process_date datetime
);

create table classifier (
    id integer primary key,
    name text not null unique
);

create table classification (
    id integer primary key,
    doc_id integer not null references document(id),
    classifier_id integer not null references classifier(id),
    certainty integer
)

--drop table word_document;
--create table word_document (
--    id integer PRIMARY KEY,
--    word_id integer references word(id),
--    doc_id text REFERENCES document(uuid),
--    total integer
--);
--drop table word_form;
create table word_form (
    id integer primary key,
    word_id integer not null references word (id),
    form text
);


-- TODO STEM tabel and STEMMING TYPES (ADJ (ATION ITY MENT..)...)
